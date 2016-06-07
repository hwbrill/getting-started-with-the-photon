int led1 = D0; // assign D0 to led1 (external led)
int led2 = D7; // assign D7 to led2 (internal led)

void setup () {
	// setting D0 & D7 as Digital Outputs
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
}

void loop () {
	digitalWrite(led1, HIGH); // ON
	delay(1000); // delay 1 second
	digitalWrite(led2, HIGH); // ON
	delay(1000); // delay 1 second
	digitalWrite(led1, LOW); // OFF
	delay(1000); // delay 1 second
	digitalWrite(led2, LOW); // OFF
	delay(1000); // delay 1 second
}
