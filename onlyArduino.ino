#include<dht.h>
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;


#define DHT11_PIN 2
dht DHT;

int moisture_sensor_pin = A0;
int light_sensor_pin = A1;
int gas_sensor_pin = A2;

//int moisture_sensor_pin = A0;
 
float moisture_sensor_value=10.0;
float temperature_sensor_value=10.0;
float humidity_sensor_value=10.0;
float light_sensor_value=10.0;

float gas_sensor_value;

float air_pressure_sensor_value=10;
float sealevel_pressure_sensor_value=10;
float altitude_sensor_value=10;
float altitude_sensor_value_2=10;


float Water_level = 10.0,pressure = 10.0, altitudevar = 10.0,rain=10.0;
void setup() {
  Serial.begin(9600);
  pinMode(DHT11_PIN,INPUT);
  pinMode(moisture_sensor_pin,INPUT);
  pinMode(light_sensor_pin,INPUT);
  pinMode(gas_sensor_pin,INPUT);
  bmp.begin();
 
}



void loop() 
{
  Serial.println();
  delay(5000);
}
