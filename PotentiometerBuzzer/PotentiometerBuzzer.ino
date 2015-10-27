void setup() {
 // initialize serial communications (for debugging only):
 Serial.begin(9600);
}

void loop() {
 // read the sensor:
 int sensorReading = analogRead(A0);
 // print the sensor reading so you know its range
 Serial.println(sensorReading);
 // map the pitch to the range of the analog input.
 // change the minimum and maximum input numbers below
 // depending on the range your sensor's giving:
 int thisPitch = map(sensorReading, 0, 1023, 440, 1047);
 // play the pitch:
 tone(9, thisPitch, 4);
 delay(5); // delay in between reads for stability
}
