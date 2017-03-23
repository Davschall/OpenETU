
const int trigButton = 7;
const int cutButton = 9;
const int motorPin = 5;
void setup() {
  //start serial connection

  Serial.begin(9600);
  //configure input pins with pullup resistors
  pinMode(trigButton, INPUT_PULLUP);
  pinMode(cutButton, INPUT_PULLUP);

  //configure output pin(s)
  pinMode(motorPin, OUTPUT);
}
bool trigFunc(bool trigPull, int cutoff)
{
  Serial.println("InsideFunc");
  while (cutoff == 1 && trigPull == false)
  {
    //Serial.println("InsideFuncLoop");
    bool trigState = false; 
    //Serial.println(trigState);
    delay(20);
    if (digitalRead(trigButton) == LOW && digitalRead(cutButton) == HIGH)
    {
      Serial.println("trigger pulled and held");
      delay(500);
      digitalWrite(motorPin, HIGH);
      delay(5);
      Serial.println("On");
    }
    else if (trigPull == true)
    {
      return;
    }
    else if (digitalRead(cutButton) == LOW)
    {
      Serial.println("cutoff button hit");
      delay(500);
      trigState = ! trigState;
       digitalWrite(motorPin, LOW);
      Serial.println(trigPull);
      delay(20);
      return trigState;
    }

  }
}
void loop() {
bool trigPull = false;
  //read the buttons value into a variable
  int trigger = digitalRead(trigButton);

  int cutoff = digitalRead(cutButton);
  //  print out the value of the buttons, and read back if it is outside the loop
  Serial.println(trigger + 5);
  //delay(500);
  Serial.println("outside");
  //delay(500);
  if(digitalRead(trigButton) == HIGH)
  {
    trigPull = false;
  }

 trigPull = trigFunc(trigPull,cutoff);
  
  while(trigPull == true && digitalRead(trigButton) == LOW)
    {
      if(digitalRead(trigButton) == LOW && digitalRead(cutButton) == HIGH)
      {
        digitalWrite(motorPin, LOW);
        Serial.println("Let go of the trigger");
        delay(20);
      }
      else if(digitalRead(trigButton) == HIGH && digitalRead(cutButton) == HIGH)
      {
        digitalWrite(motorPin, LOW);
        trigPull =! trigPull;
        Serial.println(trigPull);
        delay(20);
        break;
      }
      else if(digitalRead(trigButton) == HIGH && digitalRead(cutButton) == LOW)
      {
        digitalWrite(motorPin, LOW);
        trigPull =! trigPull;
        Serial.println(trigPull);
        delay(20);
        break;
      }
    }
  
  
  
  
  
  /*switch (cutoff)//This gives the instruction on whether or not it should reneter the while loop, cases for both during and after the cutoff switch has been hit
  {
    case 1:
      {
        if (digitalRead(trigButton) == LOW)
        {
          digitalWrite(motorPin, LOW);
          Serial.println("Let go of the Button");
          delay(10);
          break;
        }
        else if (digitalRead(trigButton) == HIGH)
        {
          digitalWrite(5, LOW);
          Serial.println("Not Holding Button");
          delay(10);
          trigPull = !trigPull;
          break;
        }
      }

    case 0:
      {
        if (digitalRead(trigButton) == LOW)
        {
          digitalWrite(motorPin, LOW);
          Serial.println("try Letting go of the Button");
          delay(10);
          break;
        }
        else if (digitalRead(trigButton) == HIGH)
        {
          Serial.println("Not Holding Button Again");
          digitalWrite(motorPin, LOW);
          delay(10);
          trigPull = !trigPull;
          break;
        }
      }
  }*/


}



