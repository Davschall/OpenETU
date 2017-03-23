bool trigpull = false;
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

void loop() {

  //read the buttons value into a variable
  int trigger = digitalRead(trigButton);

  int cutoff = digitalRead(cutButton);
  //  print out the value of the buttons, and read back if it is outside the loop
  Serial.println(trigger + 5);
  Serial.println("outside");

  
  while (cutoff == 1 && trigpull == false)
  {
    Serial.println(trigpull);
    delay(10);
    if (digitalRead(trigButton) == LOW && digitalRead(cutButton) == HIGH)
    {
      digitalWrite(motorPin, HIGH);
      delay(5);
      Serial.println("On");
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
      Serial.println("Let go of the Button");
      delay(10);
      break;
    }
    else if (digitalRead(trigButton) == HIGH)
    {
      digitalWrite(5, LOW);
      Serial.println("Not Holding Button");
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
      Serial.println("try Letting go of the Button");
      delay(10);
      break;
    }
    else if (digitalRead(trigButton) == HIGH)
    {
      Serial.println("Not Holding Button Again");
      digitalWrite(motorPin, LOW);
      delay(10);
      trigpull = !trigpull;
      break;
    }
  }
  }


}



