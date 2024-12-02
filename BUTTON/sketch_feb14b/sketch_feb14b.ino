int green = 2;
int red = 1;
int blue = 4;
void setup() {
  // put your setup code here, to run once:
pinMode(red,OUTPUT);
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(red, 255);
analogWrite(green,100);
analogWrite(blue,150);
}
