#include "TriggerFunctions.h"
const byte trigPin = 0;
const byte cutPin = 1;
const byte motorPin = 3;
//const byte selectFirePin = 6;
const byte burstPin = 2;
unsigned long previousMillis = 0;//for measuring time in case of mechanical failure.
const long interval = 10000;
void setup() {

  //configure input pins with pullup resistors
  pinMode(trigPin, INPUT_PULLUP);
  pinMode(cutPin, INPUT_PULLUP);
  //pinMode(selectFirePin, INPUT);
  pinMode(burstPin, INPUT);
  //configure output pin(s)
  pinMode(motorPin, OUTPUT);
}

void loop() {

  bool trigPull = false;
  //read the buttons value into a variable
  byte cutOff = digitalRead(cutPin);
TriggerFuncs trigObj1{byte trigPull,byte cutOff};
  while (digitalRead(burstPin) == HIGH && trigPull == false)
  {
    trigObj1.burstFunc();
  }
  //uncomment Below and comment out the function above this one for automatic fire.
  /* (digitalRead(selectFirePin) == HIGH && trigPull == false)
    {
     delay(1000);
     selectFireFunc();
    }
  */
  if (digitalRead(trigPin) == HIGH) //Just double checking that the trigger isnt held so that it can break into the first function without issue.
  {
    trigPull = false;
  }

  trigPull = trigtrigFunc(trigPull, cutOff); //Looping function that determines if youve pulled the trigger
  trigHeldFunc(trigPull);//Functions that waits for the trigger to be realeased


}
