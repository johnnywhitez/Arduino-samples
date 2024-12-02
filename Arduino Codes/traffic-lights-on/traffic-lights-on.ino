int redpin = 0;
int yellowpin = 1;
int greenpin = 4;

void setup() {
  // put your setup code here, to run once:
pinMode(redpin, OUTPUT);
pinMode(yellowpin, OUTPUT);
pinMode(greenpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(redpin, HIGH);
digitalWrite(yellowpin, HIGH);
digitalWrite(greenpin, HIGH);
}
