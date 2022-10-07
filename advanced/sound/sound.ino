
//int val=0;
void setup() {
  // put your setup code here, to run once:
pinMode(7, INPUT);
pinMode(8,OUTPUT);
Serial.begin(9600);

}

void loop() {
  
  int val= digitalRead(7);
  Serial.println(val);
  if(val == HIGH)
  {
    digitalWrite(8,HIGH);
  }
  else
  {
    digitalWrite(8,LOW);
  }
 
  
  // put your main code here, to run repeatedly:

}
