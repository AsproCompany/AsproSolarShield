/*
 Name:		AsproSolarShield.h
 Created:	12/7/2023 3:47:38 PM
 Author:	AmirSalama
 Editor:	https://www.youtube.com/@amirsalama9928/videos
*/


#ifndef _AsproSolarShield_h
#define _AsproSolarShield_h

#if defined(ARDUINO) && ARDUINO >= 100
#else
#include "WProgram.h"
#endif
class AsproSolarShield {

private:
    byte mv = A0;
    byte in = 7;
    byte cp = 6;
    byte solar = 8;
    byte DC = A1;
    byte Bs1 = A2;
    byte Bs2 = A3;

    int r_main;
    int r_dc;
    int r_Bs2;
    int r_solar;

    //(q67,pc,oc,dp,b1,b2,nc)
    int get_pc = 0;
    int get_oc = 0;
    int get_dp = 0;
    int get_b1 = 0;
    int get_b2 = 0;
    int get_nc = 0;

    int en = 0;
    int lowpower = 0;
    int lowpower2 = 0;
    int rg = 0;
    int rg2 = 0;
    int rg3 = 0;
    int rg4 = 0;

public:
    AsproSolarShield();

    void sRegister(int q67, int pc, int oc, int dp, int b1, int b2, int nc);
    void SolarBegin();
    double mVolt();
    String getInputsConnected(String x);
    String getOutUse(String y);

};

#endif

