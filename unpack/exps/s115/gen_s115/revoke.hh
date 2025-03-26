/** BEGIN_REVOKE *******************************************************
 *
 * Event revoker for EVENT.
 *
 * Do not edit - automatically generated.
 */

// EVENT
int unpack_event::__revoke_subevent(subevent_header *__header)
  // revisit aida = aida_subev(type=10,subtype=1,procid=90,control=37);
  // germanium = febex_subev(type=10,subtype=1,procid=60,control=20);
  // bplast = bplast_subev(type=10,subtype=1,procid=80,control=20);
  // frsmain = frs_main_subev(procid=10);
  // frstpc = frs_tpc_subev(procid=20);
  // frsuser = frs_user_subev(procid=30);
  // frstpat = frs_tpat_subev(procid=15);
  // frstravmus = frs_travmus_subev(procid=35,control=30);
  // ignore_unknown_subevent;
{
  int __match_no = 0;
  MATCH_SUBEVENT_DECL(1333,__match_no,1,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==37)&&(VES10_1_procid==90)),aida);
  MATCH_SUBEVENT_DECL(1334,__match_no,2,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==60)),germanium);
  MATCH_SUBEVENT_DECL(1335,__match_no,3,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==80)),bplast);
  MATCH_SUBEVENT_DECL(1337,__match_no,4,((VES10_1_procid==10)),frsmain);
  MATCH_SUBEVENT_DECL(1338,__match_no,5,((VES10_1_procid==20)),frstpc);
  MATCH_SUBEVENT_DECL(1339,__match_no,6,((VES10_1_procid==30)),frsuser);
  MATCH_SUBEVENT_DECL(1340,__match_no,7,((VES10_1_procid==15)),frstpat);
  MATCH_SUBEVENT_DECL(1342,__match_no,8,((VES10_1_control==30)&&(VES10_1_procid==35)),frstravmus);
  if (!__match_no) return 0;
  switch (__match_no)
  {
    case 1:
      REVOKE_SUBEVENT_DECL(1333,0,aida_subev,aida);
      break;
    case 2:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1334,febex_subev,germanium,0);
      REVOKE_SUBEVENT_DECL(1334,0,febex_subev,germanium);
      break;
    case 3:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1335,bplast_subev,bplast,1);
      REVOKE_SUBEVENT_DECL(1335,0,bplast_subev,bplast);
      break;
    case 4:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1337,frs_main_subev,frsmain,2);
      REVOKE_SUBEVENT_DECL(1337,0,frs_main_subev,frsmain);
      break;
    case 5:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1338,frs_tpc_subev,frstpc,3);
      REVOKE_SUBEVENT_DECL(1338,0,frs_tpc_subev,frstpc);
      break;
    case 6:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1339,frs_user_subev,frsuser,4);
      REVOKE_SUBEVENT_DECL(1339,0,frs_user_subev,frsuser);
      break;
    case 7:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1340,frs_tpat_subev,frstpat,5);
      REVOKE_SUBEVENT_DECL(1340,0,frs_tpat_subev,frstpat);
      break;
    case 8:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1342,frs_travmus_subev,frstravmus,6);
      REVOKE_SUBEVENT_DECL(1342,0,frs_travmus_subev,frstravmus);
      break;
  }
  return 0;
}

/** END_REVOKE ********************************************************/
/** BEGIN_REVOKE *******************************************************
 *
 * Event revoker for EVENT.
 *
 * Do not edit - automatically generated.
 */

// STICKY_EVENT
int unpack_sticky_event::__revoke_subevent(subevent_header *__header)
{
  int __match_no = 0;
  if (!__match_no) return 0;
  switch (__match_no)
  {
  }
  return 0;
}

/** END_REVOKE ********************************************************/
