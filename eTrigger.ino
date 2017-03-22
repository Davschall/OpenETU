/*
 Name:		eTrigger.ino
 Created:	3/21/2017 3:37:45 PM
 Author:	djsch
*/

// the setup function runs once when you press reset or power the board
#include <Bounce2.h>
const int oneButtonPin = 8; //Input button from trigger
const int twoButtonPin = 12; //Input button from cuttoff
const int motorPin = 5; //Output to mosfet
bool trigPull = false; //Variable for trigger pull
Bounce Button1 = Bounce();
Bounce Button2 = Bounce();
void setup() {
	pinMode(oneButtonPin, INPUT_PULLUP);//pin for trigger is 2
	pinMode(twoButtonPin, INPUT); //pin for cuttof is 3
	Button1.attach(oneButtonPin);
	Button1.interval(5);
	Button2.attach(twoButtonPin);
	Button2.interval(5);
		pinMode(motorPin, OUTPUT); //pin for output to mosfet is 5
}


void loop()
{
	Button1.update();//update debounce for trigger
	Button2.update();//update debounce 
	int Trig = Button1.read();
	int cutOff = Button2.read();
	while (cutOff == LOW && trigPull == false)
	{
		if (Trig == HIGH  && trigPull == false)//if trigger is pulled but has not fired
		{
			digitalWrite(motorPin, HIGH);
			trigPull != trigPull;
			
		}
		
	}
	Button1.update();
	Button2.update();
	
	switch (cutOff)
	{
	case HIGH://If the cuttoff is still high when the whille loop is exited hopefully it funnels through here
	{
		if (Trig == HIGH && trigPull == true)
		{
			digitalWrite(motorPin, LOW);

		}
		else if (Trig == LOW & trigPull == true)
		{
			digitalWrite(motorPin, LOW);
			trigPull != trigPull;	
		}
		break;
	}
	case LOW://if the cutoff is low by the time it reaches this switch we need a case to run through in order to turn off motor
	{
		if (Trig == HIGH && trigPull == true)
		{
			digitalWrite(motorPin, LOW);

		}
		else if (Trig == LOW & trigPull == true)
		{
			digitalWrite(motorPin, LOW);
			trigPull != trigPull;
		}
		break;
	}
	}


}
