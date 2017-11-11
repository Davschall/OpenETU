#include "TriggerFuncs.h
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
/*Initial function that loops until trigger is pulled
  or it calls the sleep function(hopefully when implemented)
*/
bool trigFunc(bool trigPull, int cutoff)
{

  while (cutoff == 1 && trigPull == false)
  {
    

    unsigned long currentMillis = millis();
    bool trigState = false;

    if (digitalRead(trigPin) == LOW && digitalRead(cutPin) == HIGH)
    {
      previousMillis = currentMillis;
      delay(10);
      digitalWrite(motorPin, HIGH);
    }
    else if (trigPull == true)
    {
      return;
    }
    else if (digitalRead(cutPin) == LOW)
    {
      previousMillis = currentMillis;
      trigState = ! trigState;
      digitalWrite(motorPin, LOW);
      return trigState;
    }
    else if (currentMillis > 5000)
      {
         previousMillis = currentMillis;
      trigState = ! trigState;
      digitalWrite(motorPin, LOW);
      return trigState;
        
      }
  }
}
/*

