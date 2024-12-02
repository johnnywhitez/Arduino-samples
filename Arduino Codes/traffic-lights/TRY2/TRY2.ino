int redPin = 2;
int yellowPin = 3; 
int greenPin = 4;  

void setup() {
  // Initialize the LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Turn on all LEDs
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, HIGH);
  delay(1000);  // Wait for 1 second

  // Red LED on for 2 seconds
  digitalWrite(redPin, HIGH);
  delay(2000);
  digitalWrite(redPin, LOW);

  // Yellow LED on for 2 seconds
  digitalWrite(yellowPin, HIGH);
  delay(2000);
  digitalWrite(yellowPin, LOW);

  // Green LED on for 2 seconds
  digitalWrite(greenPin, HIGH);
  delay(2000);
  digitalWrite(greenPin, LOW);
}
