/*
 Name:		AsproSolarShield.h
 Created:	12/7/2023 3:47:38 PM
 Author:	AmirSalama
 Editor:	https://www.youtube.com/@amirsalama9928/videos
*/

#include "AsproSolarShield.h"
#include <Arduino.h>

AsproSolarShield::AsproSolarShield()
{

}

 void AsproSolarShield::SolarBegin()
{
    pinMode(solar, INPUT);
    pinMode(DC, INPUT);
    pinMode(Bs1, INPUT);
    pinMode(Bs2, INPUT);

    pinMode(in, OUTPUT);
    pinMode(cp, OUTPUT);

    digitalWrite(cp, 0);
    digitalWrite(in, 0);

    digitalWrite(in, 0); 

    digitalWrite(cp, 1);
    digitalWrite(cp, 0);
    digitalWrite(cp, 1);
    digitalWrite(cp, 0);
    digitalWrite(cp, 1);
    digitalWrite(cp, 0);
    digitalWrite(cp, 1);
    digitalWrite(cp, 0);
    digitalWrite(cp, 1);
    digitalWrite(cp, 0);
    digitalWrite(cp, 1);
    digitalWrite(cp, 0);
    digitalWrite(cp, 1);
    digitalWrite(cp, 0);
    digitalWrite(cp, 1);
    digitalWrite(cp, 0);

}

 String AsproSolarShield::getInputsConnected(String x) {
    r_main = digitalRead(Bs1);
    r_dc = digitalRead(DC);
    r_Bs2 = digitalRead(Bs2);
    r_solar = digitalRead(solar);

    if (x == "solar") {
        if (r_solar == 1)
        {
            x="off";
        }
        else if (r_solar == 0)
        {
            x="on";
        }
        }
    else if (x == "dc") {
        if (r_dc == 1)
        {
            x = "off";
        }
        else if (r_dc == 0)
        {
            x = "on";
        }
    }
    else if (x == "B1") {
        if (r_main == 1)
        {
            x = "off";
        }
        else if (r_main == 0)
        {
            x = "on";
        }
    }
    else if (x == "B2") {
        if (r_Bs2 == 1)
        {
            x = "off";
        }
        else if (r_Bs2 == 0)
        {
            x = "on";
        }
    }
    return x;
}

void AsproSolarShield::sRegister(int q67 , int pc , int oc , int dp , int b1 , int b2 , int nc)
{
    digitalWrite(in, q67); ///Q6,Q7

    digitalWrite(cp, 1);
    digitalWrite(cp, 0);
    digitalWrite(cp, 1);
    digitalWrite(cp, 0);

    digitalWrite(in, pc);   ///positive_charge

    digitalWrite(cp, 1);
    digitalWrite(cp, 0);

    digitalWrite(in, oc);   ///open_charge

    digitalWrite(cp, 1);
    digitalWrite(cp, 0);
    ////////////////////////
    digitalWrite(in, dp);  ////dcpower

    digitalWrite(cp, 1);
    digitalWrite(cp, 0);

    digitalWrite(in, b1);  ////B1(main)

    digitalWrite(cp, 1);
    digitalWrite(cp, 0);

    digitalWrite(in, b2);  ///B2

    digitalWrite(cp, 1);
    digitalWrite(cp, 0);

    digitalWrite(in, nc);   ///negativ_Charge

    digitalWrite(cp, 1);
    digitalWrite(cp, 0);

    /////getter
    get_pc = pc;
    get_oc = oc;
    get_dp = dp;
    get_b1 = b1;
    get_b2 = b2;
    get_nc = nc;
}

String AsproSolarShield::getOutUse(String y) {
    if (y=="get")
    {
        if (get_dp == 1 && get_b1 == 1 && get_b2 == 0) {
            y = "DC";
        }
        else if (get_dp == 0 && get_b1 == 0 && get_b2 == 0) {
            y = "B1";
        }
        else if (get_dp == 0 && get_b1 == 1 && get_b2 == 1) {
            y = "B2";
        }
        else if (get_dp == 0 && get_b1 == 1 && get_b2 == 0) {
            y = "noPower";
        }
        else if (get_dp == 0 && get_b1 == 0 && get_b2 == 1) {
            y = "B1B2";
        }
        else
        {
            if (get_oc == 1 && get_pc == 0 && get_nc == 0 && get_dp == 1 && get_b1 == 0 && get_b2 == 0) {
                y = "DCB1";
            }
            else if (get_oc == 1 && get_pc == 1 && get_nc == 1 && get_dp == 1 && get_b1 == 1 && get_b2 == 1) {
                y = "DCB2";
            }
            else if (get_oc == 1 && get_pc == 1 && get_nc == 1 && get_dp == 1 && get_b1 == 0 && get_b2 == 1) {
                y = "DCB1B2";
            }
        }
        return y;
    }
}

double AsproSolarShield::mVolt() {
    int sensorValue = analogRead(A0);
    float voltage = sensorValue * (5.0 / 1023.0);
    if (voltage > 0.3 && voltage <= 0.7) {
        voltage = 25;
    }
    else if (voltage > 0.7 && voltage <= 1.3) {
        voltage = 50;
    }
    else if (voltage > 1.3 && voltage <= 1.5) {
        voltage = 75;
    }
    else if (voltage > 1.5 ) {
        voltage = 100;
    }
    else if ( voltage < 0.3) {
        voltage = 0;
    }
    return voltage;
}


