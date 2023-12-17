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
  String g_B2 = solar.getInputsConnected("B2");
  
  if(g_B1 == "on"){
  //(q67,positiveCharger,openCharger,DCpower,B1,B2,negativeCharger)
                //__
  //(q67,pc,oc,dp,b1,b2,nc)
  solar.sRegister(0, 0, 0, 0, 0, 0, 1); //open B1 as output and close charger
  delay(1000);
  Serial.print("B1=");
  //Battary voltage 12v require
  Serial.println(solar.mVolt());
  Serial.print("%");
  }

  if(g_B2 == "on"){
  //(q67,positiveCharger,openCharger,DCpower,B1,B2,negativeCharger)
                //__
  //(q67,pc,oc,dp,b1,b2,nc)
  solar.sRegister(0, 0, 0, 0, 1, 1, 0); //open B2 as output and close charger
  delay(1000);
  Serial.print("B2=");
  //Battary voltage 12v require
  Serial.println(solar.mVolt());
  Serial.print("%");
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
