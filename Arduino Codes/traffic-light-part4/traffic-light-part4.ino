const int redPin = 4;      // Red LED pin
const int yellowPin = 3;   // Yellow LED pin
const int greenPin = 0;    // Green LED pin
const int buttonPin = 5;   // Button pin
const int whiteLED = 6;    // White LED pin
const int triggerPin = 8;  // Ultrasonic sensor trigger pin
const int echoPin = 7;     // Ultrasonic sensor echo pin

int lightState = 0;         // 0: Lights off, 1: Red, 2: Yellow, 3: Green
bool objectDetected = false;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  turnOffAll();
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    delay(50); // Debounce
    while (digitalRead(buttonPin) == LOW) {
      // Wait for button release
      delay(50);
    }
    cycleLights();
  }
  if (lightState == 2) {
    if (checkDistance() <= 3) {
      objectDetected = true;
    } else {
      objectDetected = false;
    }
  }
  updateWhiteLED();
}

void cycleLights() {
  lightState = (lightState % 3) + 1;

  turnOffAll();

  if (lightState == 1) {
    digitalWrite(redPin, HIGH);
  } else if (lightState == 2) {
    digitalWrite(yellowPin, HIGH);
  } else if (lightState == 3) {
    digitalWrite(greenPin, HIGH);
  }
}

void turnOffAll() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(whiteLED, LOW);
}

int checkDistance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  return pulseIn(echoPin, HIGH) / 58; // Calculate distance in cm
}

void updateWhiteLED() {
  if (lightState == 2 && objectDetected) {
    digitalWrite(whiteLED, HIGH);
  } else {
    digitalWrite(whiteLED, LOW);
  }
}
