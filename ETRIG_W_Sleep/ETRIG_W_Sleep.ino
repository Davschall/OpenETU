#include <avr/sleep.h>
#include <avr/power.h>

const byte trigButton = 2;
const byte cutButton = 9;
const byte motorPin = 5;
unsigned long previousMillis = 0;//for measuring time in case of mechanical failure.
 const long interval = 15000;
void setup() {
  Serial.begin(9600);
  //configure input pins with pullup resistors
  pinMode(trigButton, INPUT_PULLUP);
  pinMode(cutButton, INPUT_PULLUP);

  //configure output pin(s)
  pinMode(motorPin, OUTPUT);
  
  
 
}
void pin2Interrupt()
{
  //detachInterrupt(digitalPinToInterrupt(trigButton));
  /* This will bring us back from sleep. */
  
  /* We detach the interrupt to stop it from 
   * continuously firing while the interrupt pin
   * is low.
   */
  
}
void enterSleep(void)
{
  
  /* Setup pin2 as an interrupt and attach handler. */
  attachInterrupt(digitalPinToInterrupt(trigButton), pin2Interrupt, LOW);
  delay(100);
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  
  sleep_enable();
  
  sleep_mode();
  
  /* The program will continue from here. */
  
  /* First thing to do is disable sleep. */
  sleep_disable(); 
  detachInterrupt(digitalPinToInterrupt(trigButton));
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
    Serial.println("In loop");
   
    unsigned long currentMillis = millis();
    bool trigState = false; 
    
    if (digitalRead(trigButton) == LOW && digitalRead(cutButton) == HIGH)
    {
      previousMillis = currentMillis;
      delay(10);
      digitalWrite(motorPin, HIGH);
    }
    else if (trigPull == true)
    {
      return;
    }
     else if (digitalRead(cutButton) == LOW)
    {
      previousMillis = currentMillis;
      trigState = ! trigState;
       digitalWrite(motorPin, LOW);
      return trigState;
    }
    else if(digitalRead(trigButton) == HIGH && digitalRead(cutButton) == HIGH && currentMillis-previousMillis >= interval)
    {
      previousMillis = currentMillis;
      digitalWrite(motorPin, LOW);
      Serial.println("Entering sleep");
      delay(1000);
      enterSleep();
      break;
    }
  }
}
void loop() {
  bool trigPull = false;
  //read the buttons value into a variable
   byte cutoff = digitalRead(cutButton);
  if(digitalRead(trigButton) == HIGH)
  {
    trigPull = false;
  }

 trigPull = trigFunc(trigPull,cutoff);
 trigHeldFunc(trigPull);
}
  
  
 
