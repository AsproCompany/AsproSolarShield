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
  
  String g_B1 = solar.getInputsConnected("B1");
  if(g_B1 == "on"){
  //(q67,positiveCharger,openCharger,DCpower,B1,B2,negativeCharger)
                //__
  //(q67,pc,oc,dp,b1,b2,nc)
  solar.sRegister(0, 0, 0, 0, 0, 0, 1); //open B1 as output and close charger
  }
  Serial.println(g_B1);
  Serial.println(solar.getOutUse("get"));
}

void loop() {
  // put your main code here, to run repeatedly:

}
