// define pins
#define BLUE 3
#define GREEN 5
#define RED 6


void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(BLUE,HIGH);
  delay(200);
  digitalWrite(RED,HIGH);
  delay(200);
  digitalWrite(GREEN,HIGH);
  delay(200);

}

void loop() {
  // put your main code here, to run repeatedly:

}
