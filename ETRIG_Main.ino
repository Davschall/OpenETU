const int trigButton = 7;
const int cutButton = 9;
const int motorPin = 5;
void setup() {
  //configure input pins with pullup resistors
  pinMode(trigButton, INPUT_PULLUP);
  pinMode(cutButton, INPUT_PULLUP);

  //configure output pin(s)
  pinMode(motorPin, OUTPUT);
}
bool trigHeldFunc(bool trigPull)
{
  while(trigPull == true && digitalRead(trigButton) == LOW)
    {
      if(digitalRead(trigButton) == LOW && digitalRead(cutButton) == HIGH)
      {
        digitalWrite(motorPin, LOW);
        delay(20);
      }
      else if(digitalRead(trigButton) == HIGH && digitalRead(cutButton) == HIGH)
      {
        digitalWrite(motorPin, LOW);
        trigPull =! trigPull;
        Serial.println(trigPull);
        break;
      }
      else if(digitalRead(trigButton) == HIGH && digitalRead(cutButton) == LOW)
      {
        digitalWrite(motorPin, LOW);
        trigPull =! trigPull;
        break;
      }
    }
}

bool trigFunc(bool trigPull, int cutoff)
{
  
  while (cutoff == 1 && trigPull == false)
  {
    
    bool trigState = false; 
    
    if (digitalRead(trigButton) == LOW && digitalRead(cutButton) == HIGH)
    {
      delay(10);
      digitalWrite(motorPin, HIGH);
    }
    else if (trigPull == true)
    {
      return;
    }
    else if (digitalRead(cutButton) == LOW)
    {
      trigState = ! trigState;
       digitalWrite(motorPin, LOW);
      return trigState;
    }

  }
}
void loop() {
bool trigPull = false;
  //read the buttons value into a variable
  int trigger = digitalRead(trigButton);

  int cutoff = digitalRead(cutButton);
  if(digitalRead(trigButton) == HIGH)
  {
    trigPull = false;
  }

 trigPull = trigFunc(trigPull,cutoff);
 trigHeldFunc(trigPull);
}
  
  
 
