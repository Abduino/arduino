/*
  Input Pull-up Serial
  It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.
  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13
*/

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(8, OUTPUT);

}

void loop() {
  int sensorVal = digitalRead(2);
  Serial.println(sensorVal);

  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}
