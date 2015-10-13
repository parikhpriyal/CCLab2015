
//define led and button pins, as well as the state of the button.
int led1 = 13;
int led2 = 12;
int buttonPin = 2;
int buttonState = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  //start the serial connection from Arduino back to computer
  //at 9600 baud
  Serial.begin(9600);
  // initialize digital pin 13 as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // initialize digital pin 2 as an input.
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  //read the state of the pin we defined as buttonPin
  //and call it buttonState
  buttonState = digitalRead(buttonPin);

  //Perform different actions depending on the state of the button
  if(buttonState == HIGH){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    Serial.println("Button Pressed");
    delay(100);
  } else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(100);
  }
}
