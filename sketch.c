#include "Arduino.h"

void setup()
{
	pinMode(13, OUTPUT);
	//Serial.begin(9600);
}

void loop()
{
	//Serial.print("Setting value\n");
	digitalWrite(13, HIGH);
	delay(1000);
	//Serial.print("Got value:");
	digitalRead(9);
	//Serial.print(digitalRead(9));
	delay(2000);
}
