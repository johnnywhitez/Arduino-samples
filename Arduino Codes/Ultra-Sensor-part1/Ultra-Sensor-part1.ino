const int trigPin = 9;  // Trig pin of the ultrasonic sensor
const int echoPin = 10; // Echo pin of the ultrasonic sensor
const int ledPin = 13;  // LED pin

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for debugging
  digitalWrite(ledPin, LOW); // Ensure the LED is initially off
}

void loop() {
  long duration, distance;
  
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the time it takes for the echo to return
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = duration / 58;
  
  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if an object is within 3 cm
  if (distance <= 160) {
    // Check if an object is closer than 1 cm
    if (distance <= 1) {
      digitalWrite(ledPin, LOW); // Turn off the LED
    } else {
      digitalWrite(ledPin, HIGH); // Turn on the LED
    }
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED
  }
  
  delay(500); // Delay for stability
}
