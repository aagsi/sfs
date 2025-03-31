void loadlib() {
   //--------------------------------------------------------------------------
   // 1. Load SFS Shared Libraries (matched to current build output)
   //--------------------------------------------------------------------------
   std::vector<TString> libs = {
      "libsfsData.so",
      "libsfsBase.so",
      "libsfssource.so",
      "libsfsMacroCompiler.so",
      "libsfsAnalysis.so"
   };

   TString libDir = "/u/profi/aali/sfsRoot/build/lib";

   for (const auto& lib : libs) {
      TString fullLibPath = libDir + "/" + lib;
      if (gSystem->Load(fullLibPath) < 0) {
         Error("loadlib", "❌ Failed to load %s", fullLibPath.Data());
         return;
      } else {
         std::cout << "✔ Loaded: " << fullLibPath << std::endl;
      }
   }

   std::cout << "✅ All SFS libraries loaded successfully.\n" << std::endl;

   //--------------------------------------------------------------------------
   // 2. Load Online Library
   //--------------------------------------------------------------------------
   TString onlineLibPaths[] = {
      "/cvmfs/fairsoft.gsi.de/debian10/fairroot/v18.8.2_jan24p1/lib/libOnline.so",
      "/cvmfs/fairsoft.gsi.de/debian10/fairsoft/jan24p1/lib/libOnline.so"
   };

   bool onlineLoaded = false;
   for (const auto& path : onlineLibPaths) {
      if (gSystem->Load(path) >= 0) {
         std::cout << "✔ Loaded Online library from: " << path << std::endl;
         onlineLoaded = true;
         break;
      }
   }

   if (!onlineLoaded) {
      Error("loadlib", "❌ Failed to load libOnline.so from all known locations.");
      return;
   }

   std::cout << "✅ Online library loaded successfully.\n" << std::endl;

   //--------------------------------------------------------------------------
   // 3. Add include paths
   //--------------------------------------------------------------------------

   const TString sfsRoot = "/u/profi/aali/sfsRoot/sfsRoot";
   const std::vector<TString> includeDirs = {
      "sfssource/base",
      "sfssource/bplast",
      "sfssource/germanium",
      "sfssource/frs",
      "analysis/online/frs",
      "analysis/online/bPlast",
      "analysis/online/germanium",
      "analysis/online/bplast",
      "analysis/online/timemachine"
   };

   for (const auto& subdir : includeDirs) {
      TString fullPath = sfsRoot + "/" + subdir;
      gInterpreter->AddIncludePath(fullPath);
      std::cout << "✔ Added include path: " << fullPath << std::endl;
   }

   const TString fairsoftIncludes[] = {
      "/cvmfs/fairsoft.gsi.de/debian10/fairsoft/jan24p1/include",
      "/cvmfs/fairsoft.gsi.de/debian10/fairroot/v18.8.2_jan24p1/include",
      "/cvmfs/fairsoft.gsi.de/debian10/fairsoft/jan24p1/include/vmc",
      "/cvmfs/fairsoft.gsi.de/debian11/fairroot/v18.8.2_jan24p1/include"
   };

   for (const auto& path : fairsoftIncludes) {
      gInterpreter->AddIncludePath(path);
      std::cout << "✔ Added external include path: " << path << std::endl;
   }

   std::cout << "\n✅ All include paths set up successfully." << std::endl;
}
