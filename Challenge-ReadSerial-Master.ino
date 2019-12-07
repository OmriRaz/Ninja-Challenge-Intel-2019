
      //============================//
     //                            //
    // 2019 Ninja Challenge Intel //
   //  Read Serial, Read!        //
  // Code Written By: Omri Raz  //
 //                            //
//============================//

//THIS CODE IS FOR THE MASTER (SENDING) ARDUINO


#include <SoftwareSerial.h>
SoftwareSerial MASTER(2,3);
String SecretCode = "Intel Ninja Challenge";
void setup() {
  Serial.begin(9600);
  MASTER.begin(9600);

}

void loop() {
  MASTER.print(SecretCode);
  delay(500);

}
