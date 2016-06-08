int ledPin = D0;
bool blinking = false;

void setup() {
	pinMode(ledPin, OUTPUT);
	Spark.function("led", ledSwitcher);
}

void loop() {
	if (blinking) {
		digitalWrite(ledPin, HIGH);
		delay(200);
		digitalWrite(ledPin, LOW);
		delay(200);
	}
}

int ledSwitcher(String command) {
	if (command.equalsIgnoreCase("on")) {
		// digitalWrite(ledPin, HIGH);
		blinking = true;
		return 1;
	}
	else if (command.equalsIgnoreCase("off")) {
		// digitalWrite(ledPin, LOW);
		blinking = false;
		return 1;
	}
	return -1;
}
