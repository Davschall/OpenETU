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

/*Initial function that loops until trigger is pulled
  or it calls the sleep function
*/
bool trigFunc(bool trigPull, int cutoff)
{
 bool trigState = false;
  while (cutoff == 1 && trigPull == false)
  {
    
    
    unsigned long currentMillis = millis();
   

    if (digitalRead(trigPin) == LOW && digitalRead(cutPin) == HIGH)
    {
      previousMillis = currentMillis;
      delay(10);
      digitalWrite(motorPin, HIGH);
    }
    else if (trigPull == true)
    {
      return trigState;
    }
    else if (digitalRead(cutPin) == LOW)
    {
      previousMillis = currentMillis;
      trigState = ! trigState;
      digitalWrite(motorPin, LOW);
      break;
    }
    else if (currentMillis > 5000)
      {
         previousMillis = currentMillis;
      trigState = ! trigState;
      digitalWrite(motorPin, LOW);
      
        
      }
  }
  return trigState;
}
/*
   Function that will not allow the program back into the trigger pulling
   function until the trigger is let go, Obviously for semi-auto
*/
bool trigHeldFunc(bool trigPull)
{
  while (trigPull == true && digitalRead(trigPin) == LOW)
  {
    if (digitalRead(trigPin) == LOW && digitalRead(cutPin) == HIGH)
    {
      
      digitalWrite(motorPin, LOW);
      delay(20);
    }
    else if (digitalRead(trigPin) == HIGH && digitalRead(cutPin) == HIGH)
    {
      digitalWrite(motorPin, LOW);
      trigPull = ! trigPull;
     
      break;
    }
    else if (digitalRead(trigPin) == HIGH && digitalRead(cutPin) == LOW)
    {
      
      digitalWrite(motorPin, LOW);
      trigPull = ! trigPull;
      break;
    }
  }
}
/*
   This function allows for full auto fire
    uncomment this for fully automatic
  void selectFireFunc()
  {
  unsigned long currentMillis = millis();
  while ( digitalRead(selectFirePin) == HIGH)
  {
    if (digitalRead(trigPin) == HIGH && currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;
      digitalWrite(motorPin, LOW);
      
      delay(1000);
      enterSleep();
      digitalWrite(motorPin, LOW);
    }
    else if (digitalRead(trigPin) == LOW)
    {
      
      previousMillis = currentMillis;
      delay(500);
      digitalWrite(motorPin, HIGH);
    }

    digitalWrite(motorPin, LOW);
  }
  }
*/
//comment/uncomment this if you want burst fire or automatic fire.
void burstFunc()
{
  bool trigPull = false;
  unsigned long currentMillis = millis();
  while ( digitalRead(burstPin) == HIGH)
  {
    

    if (digitalRead(trigPin) == LOW && trigPull == false)
    {
      
      
      for (byte tRB = 0; tRB < 3;tRB++)
      {
        digitalWrite(motorPin, HIGH);
        
        
        while(digitalRead(cutPin) == HIGH)
        
        {
        //sit here and do nothing...
     
        }
        
        
      }
      digitalWrite(motorPin,LOW);
      trigPull =! trigPull;
    }

    if (digitalRead(trigPin) == LOW)
    {
      trigPull = trigHeldFunc(trigPull);
      
    }
  }

}

void loop() {
  
  bool trigPull = false;
  //read the buttons value into a variable
  byte cutoff = digitalRead(cutPin);

  while (digitalRead(burstPin) == HIGH && trigPull == false)
  {
    burstFunc();
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

  trigPull = trigFunc(trigPull, cutoff); //Looping function that determines if youve pulled the trigger
  trigHeldFunc(trigPull);//Functions that waits for the trigger to be realeased


}
