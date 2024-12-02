int redPin = 2;
int yellowPin = 3;
int greenPin = 4;

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Turn on all lights
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, HIGH);

  delay(2000); 


  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);

  delay(1000);

  digitalWrite(redPin, HIGH);
  delay(3000);
  digitalWrite(redPin, LOW);

  
  digitalWrite(yellowPin, HIGH);
  delay(3000);
  digitalWrite(yellowPin, LOW);

  digitalWrite(greenPin, HIGH);
  delay(4000);
  digitalWrite(greenPin, LOW);
}
