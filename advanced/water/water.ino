
int val=0;
void setup() {
  // put your setup code here, to run once:
pinMode(7, INPUT);
Serial.begin(9600);

}

void loop() {
  
  val= digitalRead(7);
  Serial.println(val);
  if(val == HIGH)
  {
    tone(8,1000);
  }
  else
  {
    noTone(8);
  }

}
