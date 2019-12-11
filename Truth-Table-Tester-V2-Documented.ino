 //Code written for the Impact Labs & Intel Ninja challenge 2019 by Omri Raz
 //The code tests an external boolean function by simulating a truth table 
 //by sequencing all possible inputs for a 3 bit truth table by counting in binary and checking the output of the function.

 
      //============================//
     //                            //
    // 2019 Ninja Challenge Intel //
   //  Boolean Function Tester   //
  // Code Written By: Omri Raz  //
 //                            //
//============================//



//===================================== Defining Variables =================================//
                                                                                            //
int correct = 0;                     //Number Of Correct Function Steps                     // 
int LEDstate[3] = {0,0,0};           //Binary Count Variables                               // 
int OutputPins[3] = {2,3,4};         //2 IS LSB, 4 IS MSB                                   //
int InputPin = 5;                    //Pins For Input From The Function                     //
int inputAns[8];                     //Array for storing the input value sequence           //
int answer[8] = {0,1,1,1,0,0,1,0};   //Function Output                                      // 
//int answer[8] = {0,0,0,0,0,0,0,0}; //Debug Function Output                                //
bool Win = false;                    //Win Flag                                             //
                                                                                            //
//==================================== End Of Definitions ==================================//




//==================================== Beginning Of Main ===================================//
//                       Note: The code runs once (not in a loop)                           //
//==========================================================================================//
void setup() {
  pinMode(InputPin, INPUT);               //Setting InputPin (D5) as a digital input
  Serial.begin(9600);                     //Starting Serial Communication Over Serial at 9600 baud
  for(int i = 0; i < 3; i++){             //Using a For Loop To Define The outputPins[] Array as an output
    pinMode(OutputPins[i], OUTPUT);       //Defining OutputPins[i] As An Output
  }

  
  for(int count = 0; count < 8; count++){                    //incrementing An Integer Value (Which will get translated to binary)
    for(int bitnum = 0; bitnum < 3; bitnum++){               //Going thru 3 bits (val: 0-7 in dec) in order to set the array LEDstate as a binary counter. The function bitRead can read only one bit at a time
      LEDstate[bitnum] = bitRead(count, bitnum);             // setting the array LEDstate[] as a binary counter
       //Serial.print(LEDstate[bitnum]);                     //Uncomment for debugging
      digitalWrite(OutputPins[bitnum],LEDstate[bitnum]);     //Setting OutputPins[] as a hardware output binary counter in order to sequence through all of the possible options in a 3 bit truth table
    }
    delay(100);                                              //Delay Between each count (Not needed, But gives the Arduino a rest)
    inputAns[count] = digitalRead(InputPin);                 //Setting the array inputAns[] as the digital input received from the external boolean function
  }
//=================================== End Of Sampling ====================================//


//================================ Comparing the results =================================//
  for(int testcnt = 0; testcnt < 8; testcnt++){ //Counting from 0 to 7 in order to check the entire array
      if(inputAns[testcnt] == answer[testcnt]){ //Checking if the output from the function is equal to the data in the truth table
        correct++;                              //If the output is equal to the data, Increment the "correct" counter by 1
        Serial.println("PASS");                 
      }
      else{
        Serial.println("FAIL");
      }
  }
  Serial.print("Pass: ");
  Serial.println(correct);
 
  if(correct >= 7) {                          //If the "Correct" Counter is equal to 7 (all outputs are correct) Set var Win as true and Print WIN
    Win = true;
    Serial.println(" \n \n WIN!!");
    //================ADD WIN FUNCTION HERE ================//
    //================ADD WIN FUNCTION HERE ================//
    //================ADD WIN FUNCTION HERE ================//
    //================ADD WIN FUNCTION HERE ================//
  }
  else{
    Win = false;
    Serial.println(" \n \n LOSS");
  }
  

}

void loop() {
  // put your main code here, to run repeatedly:

}



