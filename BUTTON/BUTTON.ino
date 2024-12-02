// Define the pin number for the button
const int buttonPin = 2;
int led = 4;

// Define a variable to store the button state
int buttonState = 0;

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  
  // Set the button pin as input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == HIGH) {
    // Button is pressed
    Serial.println("Button is pressed");
  } else {
    // Button is not pressed
    Serial.println("Button is not pressed");
  }

  // Delay for a short time to debounce the button
  delay(50);
}
