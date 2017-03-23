bool trigpull = false;
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

void loop() {

  //read the buttons value into a variable
  int trigger = digitalRead(trigButton);

  int cutoff = digitalRead(cutButton);
  //  print out the value of the buttons, and read back if it is outside the loop
 
  
  while (cutoff == 1 && trigpull == false)
  {
    
    delay(10);
    if (digitalRead(trigButton) == LOW && digitalRead(cutButton) == HIGH)
    {
      digitalWrite(motorPin, HIGH);
      delay(5);
      
    }
    else if (digitalRead(cutButton) == LOW)
    {
      trigpull = !trigpull;
      digitalWrite(motorPin, LOW);
      break;
    }

  }
  switch (cutoff)//This gives the instruction on whether or not it should reneter the while loop, cases for both during and after the cutoff switch has been hit
  {
  case 1:
  {
    if (digitalRead(trigButton) == LOW)
    {
      digitalWrite(motorPin, LOW);
      delay(10);
      break;
    }
    else if (digitalRead(trigButton) == HIGH)
    {
      digitalWrite(5, LOW)
      delay(10);
      trigpull = !trigpull;
      break;
    }
  }

  case 0:
  {
    if (digitalRead(trigButton) == LOW)
    {
      digitalWrite(motorPin, LOW);
      delay(10);
      break;
    }
    else if (digitalRead(trigButton) == HIGH)
    {
      digitalWrite(motorPin, LOW);
      delay(10);
      trigpull = !trigpull;
      break;
    }
  }
  }


}



