#include<SoftwareSerial.h>
SoftwareSerial SLAVE(2,3);
String input = "0";

void setup() {
  SLAVE.begin(9600);
  Serial.begin(9600);
  
}

void loop() {
  while(SLAVE.available() > 0) {
    input = SLAVE.read();
    Serial.println("Recieved code is: " + input);
  }
}
