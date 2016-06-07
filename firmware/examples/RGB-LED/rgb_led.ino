void setup () {
	// Set Photon's built in RGB LED to be controlled by User's code
	RGB.control(true);
}

void loop () {
	// Red
	RGB.color(255,0,0);
	// Delay 2 seconds (typical)
	delay(2000);
	// Green
	RGB.color(0,255,0);
	delay(2000);
	// Blue
	RGB.color(0,0,255);
	delay(2000);
}
