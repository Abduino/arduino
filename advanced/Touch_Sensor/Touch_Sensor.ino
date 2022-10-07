int buttonpin=7;  // define D0 Sensor  Interface 

int sensorValue;
void setup()
{
Serial.begin(9600);

pinMode(buttonpin,INPUT);

}
void loop()
{
sensorValue=digitalRead(buttonpin);
Serial.print(" digital = "); 
Serial.print(sensorValue); 
Serial.println();
delay(100);
}
