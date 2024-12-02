const int buttonPin = 5; // Button pin
const int redPin = 9;    // Red LED pin
const int yellowPin = 10; // Yellow LED pin
const int greenPin = 11;  // Green LED pin
const int buzzerPin = 8; // Buzzer pin
const int triggerPin = 6; // Ultrasonic sensor trigger pin
const int echoPin = 7;    // Ultrasonic sensor echo pin

int buttonstate = 0;
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start with all LEDs off
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    // Button is pressed
    delay(50); // Debounce
    if (digitalRead(buttonPin) == LOW) {
      // Button press detected
      cycleTrafficLights();
    }
    while (digitalRead(buttonPin) == LOW) {
      // Wait for button release
      delay(50);
    }
  }
}

void cycleTrafficLights() {
  // Turn on all LEDs for 3 seconds
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, HIGH);
  delay(3000);

  // Turn off all LEDs
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);

  // Check which LED to turn on
  if (digitalRead(redPin) == LOW) {
    turnOnRedLight();
  } else if (digitalRead(yellowPin) == LOW) {
    turnOnYellowLight();
  } else if (digitalRead(greenPin) == LOW) {
    turnOnGreenLight();
  }
}

void turnOnRedLight() {
  digitalWrite(redPin, HIGH);
  digitalWrite(buzzerPin, HIGH); // Buzzer ON
  delay(4000);
  digitalWrite(buzzerPin, LOW); // Buzzer OFF
  digitalWrite(redPin, LOW);
}

void turnOnYellowLight() {
  digitalWrite(yellowPin, HIGH);
  while (digitalRead(yellowPin) == LOW) {
    if (checkDistance() <= 3) {
      digitalWrite(buzzerPin, HIGH); // Buzzer ON
    } else {
      digitalWrite(buzzerPin, LOW); // Buzzer OFF
    }
    delay(50);
  }
  digitalWrite(buzzerPin, LOW); // Buzzer OFF
  digitalWrite(yellowPin, LOW);
}

void turnOnGreenLight() {
  digitalWrite(greenPin, HIGH);
  delay(50);
  if (digitalRead(buttonPin) == LOW) {
    cycleTrafficLights(); // Button press, go back to the beginning
  }
  digitalWrite(greenPin, LOW);
}

int checkDistance() {
  // Measure distance using the ultrasonic sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  return pulseIn(echoPin, HIGH) / 58; // Calculate distance in cm
}