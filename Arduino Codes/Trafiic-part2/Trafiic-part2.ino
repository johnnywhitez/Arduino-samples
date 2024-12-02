#include "Servo.h"

const int redpin = 12;
const int yellowpin = 1;
const int greenpin = 0;
const int buttonpin = 4;
const int speakerpin = 7;
const int trigpin = 5;
const int echopin = 6;
const int servopin = 3;

int currentlight = redpin;
bool isbuttonpressed = false;
int distance = 0;

Servo servo;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
  pinMode(speakerpin, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  
  servo.attach(servopin);
  
  digitalWrite(redpin, HIGH);
  digitalWrite(yellowpin, HIGH);
  digitalWrite(greenpin, HIGH);
  delay(3000); // Turn on all lights for 3 seconds
  digitalWrite(redpin, LOW);
  digitalWrite(yellowpin, LOW);
  digitalWrite(greenpin, LOW);
  servo.write(0);
}

void loop() {
  if (digitalRead(buttonpin) == LOW && !isbuttonpressed) {
    isbuttonpressed = true;
    
    if (currentlight == redpin) {
      digitalWrite(redpin, HIGH);
      while (digitalRead(buttonpin) == LOW) {
        digitalWrite(speakerpin, HIGH);
        delay(100);
        digitalWrite(speakerpin, LOW);
        delay(100);
      }
      digitalWrite(redpin, LOW);
      digitalWrite(yellowpin, HIGH);
    } else if (currentlight == yellowpin) {
      ultrasonicDetection();
    } else {
      digitalWrite(greenpin, HIGH);
      servo.write(90); // Adjust the angle as needed
      while (digitalRead(buttonpin) == LOW) {
        // Keep the servo running
      }
    }
    
    currentlight = (currentlight == redpin) ? yellowpin : (currentlight == yellowpin) ? greenpin : redpin;
    
  } else if (digitalRead(buttonpin) == HIGH) {
    isbuttonpressed = false;
  }
}

void ultrasonicDetection() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigpin, LOW);
  
  distance = pulseIn(echopin, HIGH) / 58;
  
  if (distance <= 3) { // Detects objects within 3 cm
    digitalWrite(speakerpin, HIGH);
    delay(2000); // Buzz the buzzer for 2 seconds
    digitalWrite(speakerpin, LOW);
  }
}
