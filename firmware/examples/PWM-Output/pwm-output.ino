int ledPin = D0;
int switchPin = D1;

int brightness = 0;

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
	if (digitalRead(switchPin) == LOW) {
		brightness += 25;
		if (brightness > 255) {
			brightness = 0;
		}
		analogWrite(ledPin, brightness);
		delay(200);
	}
}
