int dot = 200;
int dash = dot * 3;

void setup () {
	// Set Photon's built in RGB LED to be controlled by User's code
	RGB.control(true);
}

void loop () {
	// flash 'S' ...
	flashS();
	flashO();
	flashS();
	// flash 'O' ---
/*	flash(600,200);
	flash(600,200);
	flash(600,600);
	// flash 'S' ...
	flash(200,200);
	flash(200,200);
	flash(200,600);
*/
	delay(2000); // delay before repeat
}

void flash(int duration, int gap) {

RGB.color(255,255,255);
delay(duration);
RGB.color(0,0,0);
delay(gap);

}

void flashS() {
	flash(dot, dot);
	flash(dot, dot);
	flash(dot, dash);
}

void flashO() {
	flash(dash, dot);
	flash(dash, dot);
	flash(dash, dash);
}
