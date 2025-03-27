#!/bin/bash

# ========================================================
# Script: interactive_rename_and_replace_sfs.sh
# Description:
#   - Interactive renaming and content replacement for "sfs"→"sfs" and "SFS"→"SFS".
#   - Also replaces "sfsReader"→"sfsReader", "SFSReader"→"SFSReader", plus sfsLogger→sfsLogger, sfsLOG→sfsLOG.
#   - Shows each proposed change one by one, waits for user input [y/n/z/q].
#   - 'z' (undo) reverts the last change; 'q' skips remaining lines in the current file.
# Usage:
#   ./interactive_rename_and_replace_sfs.sh /path/to/project
# ========================================================

TARGET_DIR="${1:-.}"

BACKUP_EXT=".bak"
BACKUP_DIR="/u/profi/aali/sfsRoot/tmp"
mkdir -p "$BACKUP_DIR"

UNDO_LOG="/tmp/rename_undo.log"
> "$UNDO_LOG"  # Clear any previous undo log.

echo "🔍 Starting in directory: $TARGET_DIR"
echo "🔁 Interactive mode enabled"
echo "------------------------------------------------------"
echo "Prompt options for each change:"
echo "  [y] = yes (apply change)"
echo "  [n] = no  (skip this single change)"
echo "  [z] = undo last change (revert last rename/line-change)"
echo "  [q] = skip the rest of the current file"
echo "------------------------------------------------------"

# -------------------------------------
# Undo last action from UNDO_LOG
# -------------------------------------
undo_last_change() {
    local last_action
    last_action=$(tail -n 1 "$UNDO_LOG")
    if [[ -z "$last_action" ]]; then
        echo "⚠️  No changes to undo."
        return
    fi

    local type src dst lineNum
    type=$(echo "$last_action" | cut -d':' -f1)
    src=$(echo "$last_action"  | cut -d':' -f2)
    dst=$(echo "$last_action"  | cut -d':' -f3)

    # --------------------------
    # 1) Undo file/folder rename
    # --------------------------
    if [[ "$type" == "rename" ]]; then
        if [[ -e "$dst" ]]; then
            mv "$dst" "$src"
            echo "↩️  Undone rename: $dst → $src"
        else
            echo "⚠️  Cannot find $dst to revert rename!"
        fi
        sed -i '$d' "$UNDO_LOG"
        return
    fi

    # --------------------------------------
    # 2) Undo whole-file content replacement
    # --------------------------------------
    if [[ "$type" == "content" ]]; then
        if [[ -e "$dst" ]]; then
            cp "$dst" "$src"
            echo "↩️  Undone content change in: $src"
        else
            echo "⚠️  Cannot find $dst to revert content!"
        fi
        sed -i '$d' "$UNDO_LOG"
        return
    fi

    # -------------------------------------------
    # 3) Undo single-line content replacement
    # -------------------------------------------
    if [[ "$type" == "content-line" ]]; then
        lineNum=$(echo "$last_action" | cut -d':' -f4)
        if [[ -e "$dst" ]]; then
            cp "$dst" "$src"
            echo "↩️  Undone line #$lineNum change in: $src"
        else
            echo "⚠️  Cannot find $dst to revert line #$lineNum!"
        fi
        sed -i '$d' "$UNDO_LOG"
        return
    fi
}

# -------------------------------------
# Helper: line-by-line content replacement
# -------------------------------------
process_file_line_by_line() {
    local file="$1"
    local pattern="$2"
    local sed_expr="$3"

    # Gather all lines matching $pattern (with line numbers).
    mapfile -t matches < <(grep -nE "$pattern" "$file" 2>/dev/null)
    if (( ${#matches[@]} == 0 )); then
        return 0  # no matches
    fi

    for match in "${matches[@]}"; do
        local lineNum="${match%%:*}"
        local lineContent="${match#*:}"

        # If the file changed such that this line no longer matches, skip it.
        if ! echo "$lineContent" | grep -Eq "$pattern"; then
            continue
        fi

        # -------------------------------
        # Skip lines containing:
        #   music, MUSIC, tpc, TPC,
        #   SC4, sc4, Sc4,
        #   qdc4, QDC4, Qdc4
        # -------------------------------
        if echo "$lineContent" | grep -Eq 'music|MUSIC|tpc|TPC|SC4|sc4|Sc4|qdc4|QDC4|Sync48|Qdc4'; then
            echo "Skipping line $lineNum (contains forbidden pattern)."
            continue
        fi

        echo -e "\nFound in file '$file' (line $lineNum):"
        echo ">>> $lineContent"

        while true; do
            read -p "Replace (sfs→sfs, SFS→SFS, sfsLogger→sfsLogger, etc.) in this line? [y/n/z/q]: " choice < /dev/tty
            case "$choice" in
                y|Y)
                    local timestamp
                    timestamp=$(date +%s%N)
                    local backup_file="${BACKUP_DIR}/$(basename "$file")${BACKUP_EXT}.${timestamp}.${lineNum}"

                    cp "$file" "$backup_file"
                    # Apply the replacements ONLY on this line.
                    sed -i \
                        -e "${lineNum}s/sfsLogger/sfsLogger/g" \
                        -e "${lineNum}s/sfsLOG/sfsLOG/g" \
                        -e "${lineNum}s/sfs/sfs/g" \
                        -e "${lineNum}s/SFSLogger/SFSLogger/g" \
                        -e "${lineNum}s/SFSLOG/SFSLOG/g" \
                        -e "${lineNum}s/SFS/SFS/g" \
                        "$file"

                    echo "content-line:$file:$backup_file:$lineNum" >> "$UNDO_LOG"
                    break
                    ;;
                n|N)
                    echo "⏭️  Skipped line $lineNum."
                    break
                    ;;
                z|Z)
                    undo_last_change
                    ;;
                q|Q)
                    echo "🛑 Skipping the rest of this file ($file)."
                    return 0
                    ;;
                *)
                    echo "⚠️  Invalid choice. Use [y], [n], [z], or [q]."
                    ;;
            esac
        done
    done
}

# -------------------------------------
# Step 1: Rename files and directories
# -------------------------------------
echo -e "\n📂 Checking files/directories to rename..."
while read -r oldpath; do
    newpath=$(echo "$oldpath" | sed -e 's/sfs/sfs/g' -e 's/SFS/SFS/g')
    if [[ "$oldpath" != "$newpath" ]]; then
        echo -e "\n🔁 Rename suggestion:"
        echo "FROM: $oldpath"
        echo "  TO: $newpath"

        while true; do
            read -p "Apply this rename? [y/n/z]: " choice < /dev/tty
            case "$choice" in
                y|Y)
                    mv "$oldpath" "$newpath"
                    echo "rename:$oldpath:$newpath" >> "$UNDO_LOG"
                    break
                    ;;
                n|N)
                    echo "⏭️  Skipped rename."
                    break
                    ;;
                z|Z)
                    undo_last_change
                    ;;
                *)
                    echo "⚠️  Invalid choice. Please enter [y], [n], or [z]."
                    ;;
            esac
        done
    fi
done < <(find "$TARGET_DIR" -depth \( -name '*sfs*' -o -name '*SFS*' \))

# -------------------------------------
# Step 2: Replace content in text files (line-by-line)
# -------------------------------------
echo -e "\n📝 Checking file contents for 'sfs' or 'SFS'..."
while read -r file; do
    [[ -f "$file" ]] || continue
    if file "$file" | grep -q "binary"; then
        continue
    fi

    if grep -q -E 'sfs|SFS' "$file"; then
        process_file_line_by_line "$file" 'sfs|SFS' 's/sfs/sfs/g; s/SFS/SFS/g'
    fi
done < <(find "$TARGET_DIR" -type f)

# -------------------------------------
# Step 3: Patch CMakeLists.txt references (line-by-line)
# -------------------------------------
echo -e "\n🛠 Checking CMakeLists.txt for 'sfsReader' or 'SFSReader'..."
while read -r cmakefile; do
    if grep -q -E 'sfsReader|SFSReader' "$cmakefile"; then
        process_file_line_by_line "$cmakefile" 'sfsReader|SFSReader' 's/sfsReader/sfsReader/g; s/SFSReader/SFSReader/g'
    fi
done < <(find "$TARGET_DIR" -type f -name "CMakeLists.txt")

# -------------------------------------
# Final Summary
# -------------------------------------
echo -e "\n✅ Done!"
echo "🧯 Backup files saved under: $BACKUP_DIR"
echo "📜 Undo log stored at: $UNDO_LOG"
echo "🧹 To remove backups, run:"
echo "    find \"$BACKUP_DIR\" -type f -name \"*${BACKUP_EXT}*\" -delete"
