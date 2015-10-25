//reference code from http://www.instructables.com/id/Easy-ultrasonic-4-pin-sensor-monitoring-hc-sr04/

int trig = 3; // attach pin 3 to Trig
int echo = 4; //attach pin 4 to Echo
int bled = 6; //attach pin 6 to Blue LED
int yled = 9; //attach pin 6 to Yellow LED


void setup() {
// initialize serial communication:
pinMode(echo,INPUT);
pinMode(trig, OUTPUT);
pinMode(bled, OUTPUT);
pinMode(yled, OUTPUT);
Serial.begin(9600);
}

void loop()
{
  
// establish variables for duration of the ping,
// and the distance result in inches and centimeters:
long duration, inches, cm;

// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(5);
digitalWrite(trig, LOW);

// The same pin is used to read the signal from the PING))): a HIGH
// pulse whose duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
duration = pulseIn(echo, HIGH);

// convert the time into a distance
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);

Serial.print(inches);
Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.println();

if (inches > 10){
  digitalWrite (bled, LOW);  
  digitalWrite (yled, HIGH);  
} else{
  digitalWrite (bled, HIGH);
  digitalWrite (yled, LOW);
}

delay(100);
}

long microsecondsToInches(long microseconds)
{
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we divide by 2 to get the distance of the obstacle.
return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}
