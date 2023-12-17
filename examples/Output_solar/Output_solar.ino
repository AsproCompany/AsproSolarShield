/*Aspro Company 
 * Eng:Amir Salama
 * https://www.youtube.com/@amirsalama9928/videos
 * https://www.facebook.com/groups/2187431451581099
 * https://www.facebook.com/profile.php?id=100091664624422
 */

#include "AsproSolarShield.h"

AsproSolarShield solar;

void setup() {
  Serial.begin(9600);
  solar.SolarBegin(); //default B1 as output
  
  //step1
  //remove B1 or B2 and dc power
  // if dc connected prefer dc and reject solar
  //step2
  //active charger in removed B1 or B2
  //step3
  //active that B1 or B2 as output

  //for exampl B1 is removed
  String g_B1 = solar.getInputsConnected("B1");
  if(g_B1 == "off"){
  //(q67,positiveCharger,openCharger,DCpower,B1,B2,negativeCharger)
                //__
  //(q67,pc,oc,dp,b1,b2,nc)
  solar.sRegister(0, 0, 1, 0, 0, 0, 0); //open B1 as output and open charger
  }

  //for exampl B2 is removed
  /*String g_B2 = solar.getInputsConnected("B2");
  if(g_B2 == "off"){
  //(q67,positiveCharger,openCharger,DCpower,B1,B2,negativeCharger)
                //__
  //(q67,pc,oc,dp,b1,b2,nc)
  solar.sRegister(0, 0, 1, 0, 1, 1, 0); //open B2 as output and open charger
  }*/
}

void loop() {
  // put your main code here, to run repeatedly:

}
