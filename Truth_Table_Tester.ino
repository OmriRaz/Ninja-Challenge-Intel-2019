      //============================//
     //                            //
    // 2019 Ninja Challenge Intel //
   //  Boolean Function Tester   //
  // Code Written By: Omri Raz  //
 //                            //
//============================//

int correct = 0;                     //Number Of Correct Function Steps
int LEDstate[3] = {0,0,0};           //Binary Count Variables
int OutputPins[3] = {2,3,4};         //2 IS LSB, 4 IS MSB
int InputPins[2] = {5,6};            //Pins For Input From The Function
int answer[8] = {0,1,1,1,0,0,1,0};   //Function Output
bool Win = false;                    //Win Flag


void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 3; i++){
    pinMode(OutputPins[i], OUTPUT);
    if(i < 2){
      pinMode(InputPins[i], INPUT);
    }
  }
  for(int count = 0; count < 8; count++){ //counting integer
    Serial.print("Count: ");
    Serial.println(count);
    Serial.print("Binary count: ");
    for(int bitnum = 0; bitnum < 3; bitnum++){
      LEDstate[bitnum] = bitRead(count, bitnum);
      if(LEDstate[bitnum] == answer[bitnum]){
        correct++;
      }
      else{
        Serial.println("FAIL");
      }
      Serial.print(LEDstate[bitnum]);
      digitalWrite(OutputPins[bitnum],LEDstate[bitnum]);
    } 
    delay(3000);
  }
  if(correct >= 7) {
    Win = true;
    Serial.println("WIN!!");
    
  }
  else{
    Win = false;
    Serial.println("loss");
  }
  

}

void loop() {
  // put your main code here, to run repeatedly:

}



