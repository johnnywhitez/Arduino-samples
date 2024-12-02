const int redPin = 4;     // Red LED pin
const int yellowPin = 3; // Yellow LED pin
const int greenPin = 0;  // Green LED pin

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Turn on the red light and delay for a second
  digitalWrite(redPin, HIGH);
  delay(1000);

  // Turn off the red light and delay for a second
  digitalWrite(redPin, LOW);
  delay(1000);

  // Turn on the green light and delay for a second
  digitalWrite(greenPin, HIGH);
  delay(1000);

  // Turn off the green light and delay for a second
  digitalWrite(greenPin, LOW);
  delay(1000);

  // Turn on the yellow light and delay for a second
  digitalWrite(yellowPin, HIGH);
  delay(1000);

  // Turn off the yellow light and delay for a second
  digitalWrite(yellowPin, LOW);
  delay(1000);
}
