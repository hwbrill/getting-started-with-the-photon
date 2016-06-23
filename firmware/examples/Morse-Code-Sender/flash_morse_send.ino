String message = "";

int ledPin = D0;
int switchPin = D1;

int pezoPin = A4;
bool flashing = false;

int dot = 200;
int dash = dot * 3;
// Morse Code Array
String letters[] = {
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // a-i : A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // j-r : J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // s-z : S-Z
};

void setup() {
	// RGB.control(true);
	pinMode(ledPin, OUTPUT);
	pinMode(switchPin, INPUT_PULLUP);
	pinMode(pezoPin, OUTPUT);
	Spark.function("morse", startFlashing);
}

void loop() {
	// if (digitalRead(switchPin) == LOW) {
	if (flashing) {
		flashMessage(message);
		flashing = false;
	}
	// delay(5000); // 5 second delay before repeat
}

int startFlashing(String param) {
	if (param.length() <= 63) {
		message = param;
		flashing = true;
		return 1;
	}
	else {
		return -1; // message too long
	}
}

void flashMessage(String message) {
	for (int i = 0; i < message.length(); i++) {
		char letter = message.charAt(i); // extract the letters from the message
		flashLetter(letter);
	}
}

void flashLetter(char letter) {
	if (letter >= 'a' && letter <= 'z') { // lowercase
		flashDotsOrDashes(letters[letter - 'a']);
	} // or
	else if (letter >= 'A' && letter <= 'Z') { // uppercase
		flashDotsOrDashes(letters[letter - 'A']);
	} // or
	else if (letter = ' ') { // space
		delay(dot * 7); // gap between words
	}
}

void flashDotsOrDashes(String dotsAndDashes) {
	for (int i = 0; i < dotsAndDashes.length(); i++) {
		char dotOrDash = dotsAndDashes.charAt(i); // extract either a dot or dash
		if (dotOrDash == '.') {
			flash(dot);
		}
		else {
			flash(dash);
		}
		delay(dot); // gap between dots and dashes of a letter
	}
	delay(dash - dot); // gap between letters of a words
}

void flash(int duration) {
	//RGB.color(255,255,255);
	digitalWrite(ledPin, HIGH);
	tone(pezoPin, 1000);
	delay(duration);
	noTone(pezoPin);
	//RGB.color(0,0,0);
	digitalWrite(ledPin, LOW);
}
