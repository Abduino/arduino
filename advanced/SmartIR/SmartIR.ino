#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 8;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

int sensorD = 7;
int sensorA = A0;
int SensorValueA;
int SensorValueD;
void setup() {
Serial.begin(9600);
  pinMode(sensorD, INPUT); 
  pinMode(sensorA, INPUT); //use pimode function to set pin 13 as input device
  Serial.println("** program start **");
}
void loop() {
   /* float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");
  */
  int SensorValueA = analogRead(sensorA);
  Serial.print("Analog = ");
  Serial.print(SensorValueA);
  int SensorValueD = digitalRead(sensorD);
  Serial.print(" ***** Digital = ");
  Serial.print(SensorValueD);
  Serial.println();



  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer,HIGH);

  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer,LOW);
  }
  delay(1000);
}

#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 8;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup( )
{
Serial.begin( 9600);
}
void loop( )
{
float temperature;
float humidity;
if(dht_sensor.measure(&temperature, &humidity)){
//Serial.print( "T = " );
Serial.print( temperature, 2 );
//Serial.print( " deg. C, H = " );
Serial.print( humidity, 2 );
Serial.println( "%" );
}
}
