int reading = 0;
double volts = 0.0;
int analogPin = A0;

void setup() {
	Spark.variable("analog", &reading, INT); // raw
	Spark.variable("volts", &volts, DOUBLE); // eng
}

void loop() {
	reading = analogRead(analogPin); // raw value is from 0 - 4096
	volts = reading * 3.3 / 4096.0; // eng value is from 0 - 3.3
}
