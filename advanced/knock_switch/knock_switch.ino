int Led=13; 
int Shock=8;
int val; 
void setup()
{
Serial.begin(9600);
pinMode(Led,OUTPUT); 
pinMode(Shock,INPUT);
}
void loop()
{
val=digitalRead(Shock);
Serial.println(val);
if(val==HIGH)
{
  Serial.println("HIGH");
digitalWrite(Led,LOW);
}
else
{
  Serial.println("LOW");
digitalWrite(Led,HIGH);
}
delay(1000);
}
