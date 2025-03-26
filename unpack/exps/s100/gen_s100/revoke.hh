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
  // fatima = fatima_tamex_subev(type=10,subtype=1,procid=75,control=20);
  // fatimavme = fatima_vme_subev(type=10,subtype=1,procid=70,control=20);
  // bplast = bplast_subev(type=10,subtype=1,procid=80,control=20);
  // bgo = bgo_tamex_subevent(procid=100);
  // frsmain = frs_main_subev(procid=10);
  // frstpc = frs_tpc_subev(procid=20);
  // frsuser = frs_user_subev(procid=30);
  // frstpat = frs_tpat_subev(procid=15);
  // beammonitor = bm_subev(procid=1);
  // ignore_unknown_subevent;
{
  int __match_no = 0;
  MATCH_SUBEVENT_DECL(1484,__match_no,1,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==37)&&(VES10_1_procid==90)),aida);
  MATCH_SUBEVENT_DECL(1485,__match_no,2,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==60)),germanium);
  MATCH_SUBEVENT_DECL(1486,__match_no,3,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==75)),fatima);
  MATCH_SUBEVENT_DECL(1487,__match_no,4,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==70)),fatimavme);
  MATCH_SUBEVENT_DECL(1488,__match_no,5,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==80)),bplast);
  MATCH_SUBEVENT_DECL(1489,__match_no,6,((VES10_1_procid==100)),bgo);
  MATCH_SUBEVENT_DECL(1491,__match_no,7,((VES10_1_procid==10)),frsmain);
  MATCH_SUBEVENT_DECL(1492,__match_no,8,((VES10_1_procid==20)),frstpc);
  MATCH_SUBEVENT_DECL(1493,__match_no,9,((VES10_1_procid==30)),frsuser);
  MATCH_SUBEVENT_DECL(1494,__match_no,10,((VES10_1_procid==15)),frstpat);
  MATCH_SUBEVENT_DECL(1496,__match_no,11,((VES10_1_procid==1)),beammonitor);
  if (!__match_no) return 0;
  switch (__match_no)
  {
    case 1:
      REVOKE_SUBEVENT_DECL(1484,0,aida_subev,aida);
      break;
    case 2:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1485,febex_subev,germanium,0);
      REVOKE_SUBEVENT_DECL(1485,0,febex_subev,germanium);
      break;
    case 3:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1486,fatima_tamex_subev,fatima,1);
      REVOKE_SUBEVENT_DECL(1486,0,fatima_tamex_subev,fatima);
      break;
    case 4:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1487,fatima_vme_subev,fatimavme,2);
      REVOKE_SUBEVENT_DECL(1487,0,fatima_vme_subev,fatimavme);
      break;
    case 5:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1488,bplast_subev,bplast,3);
      REVOKE_SUBEVENT_DECL(1488,0,bplast_subev,bplast);
      break;
    case 6:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1489,bgo_tamex_subevent,bgo,4);
      REVOKE_SUBEVENT_DECL(1489,0,bgo_tamex_subevent,bgo);
      break;
    case 7:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1491,frs_main_subev,frsmain,5);
      REVOKE_SUBEVENT_DECL(1491,0,frs_main_subev,frsmain);
      break;
    case 8:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1492,frs_tpc_subev,frstpc,6);
      REVOKE_SUBEVENT_DECL(1492,0,frs_tpc_subev,frstpc);
      break;
    case 9:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1493,frs_user_subev,frsuser,7);
      REVOKE_SUBEVENT_DECL(1493,0,frs_user_subev,frsuser);
      break;
    case 10:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1494,frs_tpat_subev,frstpat,8);
      REVOKE_SUBEVENT_DECL(1494,0,frs_tpat_subev,frstpat);
      break;
    case 11:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1496,bm_subev,beammonitor,9);
      REVOKE_SUBEVENT_DECL(1496,0,bm_subev,beammonitor);
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
