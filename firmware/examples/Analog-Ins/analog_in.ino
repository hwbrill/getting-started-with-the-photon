int reading = 0;
int analogPin = A0;

void setup() {
	Spark.variable("analog", &reading, INT);
}

void loop() {
	reading = analogRead(analogPin);
}
