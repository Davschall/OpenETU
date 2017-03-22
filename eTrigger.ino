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
bool lastState = LOW;
Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();
void setup() {
	pinMode(oneButtonPin, INPUT_PULLUP);//pin for trigger is 2
	pinMode(twoButtonPin, INPUT); //pin for cuttof is 3
	debouncer1.attach(oneButtonPin);
	debouncer1.interval(5);
	debouncer2.attach(twoButtonPin);
	debouncer2.interval(5);
		pinMode(motorPin, OUTPUT); //pin for output to mosfet is 5
}


void loop()
{


}
