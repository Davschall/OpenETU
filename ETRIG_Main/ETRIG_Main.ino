const int trigButton = 7;
const int cutButton = 9;
const int motorPin = 5;
unsigned long previousMillis = 0;//for measuring time in case of mechanical failure.
 const long interval = 10000;
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

bool trigFunc(bool trigPull, int cutoff)//initial loop that waits until trigger is pulled
{
  
  while (cutoff == 1 && trigPull == false)
  {
    unsigned long currentMillis = millis();
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
      if (digitalRead(cutButton) == LOW)
    {
      trigState = ! trigState;
       digitalWrite(motorPin, LOW);
      return trigState;
    }
    else if(currentMillis-previousMillis >= interval)//in case of mechanical failure
    {
      digitalWrite(motorPin, LOW);
      previousMillis = currentMillis;
      break;
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
  
  
 
