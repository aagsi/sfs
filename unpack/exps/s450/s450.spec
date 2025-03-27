// -*- C++ -*-

#include "../../common/whiterabbit.spec"
#include "../../common/gsi_tamex4.spec"
#include "../../common/gsi_febex4.spec" // gsi_febex4.spec
// CEJ: grab setup file from S450 and stick in sfsRoot/config/s450/...
#include "../../../config/s452/setup.hh" 

SUBEVENT(febex_subev)
{
    ts = TIMESTAMP_WHITERABBIT(id=0x400); // can be autogenerated or simply in config.

    select several
    {
        padding = FEBEX_PADDING();
    }
    select several
    {   // do once per card
        data[0] = FEBEX_EVENT(card = 0);
        data[1] = FEBEX_EVENT(card = 1);
        data[2] = FEBEX_EVENT(card = 2);
        data[3] = FEBEX_EVENT(card = 3);
    }
}

SUBEVENT(bplast_tamex_subev)
{
    ts = TIMESTAMP_WHITERABBIT(id=0x500);
    trigger_window = TAMEX4_HEADER();
    select several 
    {
        padding = TAMEX4_PADDING();
    }
    select several
    {
        tamex[0] = TAMEX4_SFP(sfp=0,card=0);
        tamex[1] = TAMEX4_SFP(sfp=0,card=1);
        tamex[2] = TAMEX4_SFP(sfp=0,card=2);
        tamex[3] = TAMEX4_SFP(sfp=0,card=3);
        tamex[4] = TAMEX4_SFP(sfp=0,card=4);
        tamex[5] = TAMEX4_SFP(sfp=0,card=5);
        tamex[6] = TAMEX4_SFP(sfp=0,card=6);
        tamex[7] = TAMEX4_SFP(sfp=0,card=7);
        tamex[8] = TAMEX4_SFP(sfp=0,card=8);
    }  
}


EVENT
{   
    // CEJ: UNCOMMENT SUBEVENTS YOU'RE INTERESTED IN HERE

    //revisit aida = aida_subev(type = 10, subtype = 1, procid = 90, control = 37);
    germanium = febex_subev(type = 10, subtype = 1, procid = 60, control = 20);
    //fatima_vme = fatima_vme_subev(type = 10, subtype = 1, procid = 70, control = 20, subcrate = 0);
    //fatima = fatima_tamex_subev(type = 10, subtype = 1, procid = 80, control = 20, subcrate = 0);
    //bplast = bplast_tamex_subev(type = 10, subtype = 1, procid = 80, control = 20, subcrate = 0);

    // CEJ: NONE OF THIS WILL WORK WITH S450
    // white rabbit should be easy, do with Elisa wed
    // frs_whiterabbit = frs_whiterabbit_subev(type = 10, subtype = 1, procid = 10, control = 20); // whiterabbit
    // come back to
    // frs_main_crate = frs_main_crate_subev(type = 12, subtype = 1, procid = 10, control = 20); // main crate
    // // start extraction here
    // tpat = frs_tpat_subev(type = 36, subtype = 3600, procid = 10, control = 20); // tpat // works // 
    // frs_tof_crate = frs_tof_crate_subev(type = 12, subtype = 1, procid = 35, control = 20); // VFTX, MQDC, SIS 3820
    // frs_tpc_crate = frs_tpc_crate_subev(type = 12, subtype = 1, procid = 20, control = 21); // frs_main_scaler // music?
    // frs_crate = frs_crate_subev(type = 12, subtype = 1, procid = 30, control = 20); // sci_tx? // "frs crate"? // scaler_frs is here*/

    ignore_unknown_subevent;
};

// #include "mapping.hh"
