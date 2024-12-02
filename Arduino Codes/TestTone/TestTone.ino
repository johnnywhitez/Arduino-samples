#define BUTTON 3
#define BUZZER 2

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);    
}

void loop() {
  if (digitalRead(BUTTON) == LOW) { 
    playTone(500, 200); 
  }
}

void playTone(int frequency, int duration) {
  tone(BUZZER, frequency, duration); 
  delay(duration + 20); 
  noTone(BUZZER); 
}
