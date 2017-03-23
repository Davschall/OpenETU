bool trigPull = false;
//const int trigButton = 1;
//const int cutPin = 2;
//const int motorPin = 3;
void setup() 
{
  pinMode(1, INPUT);
  pinMode(2, INPUT);

  //configure output pin(s)
  pinMode(3, OUTPUT);
}
bool trigFunc(bool trigPull)
{
 while (digitalRead(2) == LOW && trigPull == false)
  {
    if (digitalRead(1) == HIGH && digitalRead(2) == LOW)
    {
      delay(23);
      digitalWrite(3, HIGH);
      delay(5);
      
    }
    if (digitalRead(2) == HIGH)
    {
      delay(23);
      trigPull = !trigPull;
       digitalWrite(3, LOW);
      return trigPull;
    }

  }
}
void loop() {
digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  delay(1533);               // wait for a second    // turn the LED off by making the voltage LOW
  digitalWrite(3, LOW); 
  delay(1533);
  //read the buttons value into a variable
  int trigger = digitalRead(1);

  int cutoff = digitalRead(2);
  //  print out the value of the buttons, and read back if it is outside the loop
 
  if(digitalRead(1) == LOW)
  {
    trigPull = false;
  }

 trigPull = trigFunc(trigPull);
  
  while(trigPull == true && digitalRead(1) == HIGH)
    {
      if(digitalRead(1) == HIGH && digitalRead(2) == LOW)
      {
        digitalWrite(3, LOW);
        
        
      }
      else if(digitalRead(1) == LOW && digitalRead(2) == LOW)
      {
        digitalWrite(3, LOW);
        trigPull =! trigPull;
        break;
      }
      else if(digitalRead(1) == LOW && digitalRead(2) == HIGH)
      {
        digitalWrite(3, LOW);
        trigPull =! trigPull;
        break;
      }
    }
}

