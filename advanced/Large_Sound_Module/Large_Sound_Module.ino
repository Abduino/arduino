
int buttonpin=7;  // define D0 Sensor  Interface 
int sensorPin = A0; 
int sensorValue = 0; 

void setup()
{
Serial.begin(9600);

pinMode(buttonpin,INPUT);
pinMode(sensorPin,INPUT);
}
void loop()
{
sensorValue = analogRead(sensorPin);
Serial.print(" analog = "); 
Serial.println(sensorValue, DEC); 
sensorValue=digitalRead(buttonpin);
Serial.print(" digital = "); 
Serial.print(sensorValue); 
Serial.println();
delay(1000);
}
