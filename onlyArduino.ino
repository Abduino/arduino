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
    float temperature =bmp.readTemperature(); //*c
    air_pressure_sensor_value = bmp.readPressure(); //pa
    altitude_sensor_value = bmp.readAltitude(); //meters
    altitude_sensor_value_2 = bmp.readAltitude(101500);
    sealevel_pressure_sensor_value = bmp.readSealevelPressure(); //pa

    int chk = DHT.read11(DHT11_PIN);
    temperature_sensor_value = DHT.temperature;
    humidity_sensor_value = DHT.humidity;
    moisture_sensor_value = analogRead(moisture_sensor_pin);
    light_sensor_value = map(analogRead(light_sensor_pin), 0, 1000, 1000, 0);
    gas_sensor_value = analogRead(gas_sensor_pin);
    float sensor_volt;
    float RS_gas;
    sensor_volt=gas_sensor_value/1024*5.0;
    RS_gas = (5.0-sensor_volt)/sensor_volt;
    Serial.print("Soil Moisture = ");
    Serial.print(moisture_sensor_value);
    Serial.print(",");
    Serial.print("Temperature = ");
    Serial.print(temperature_sensor_value);
    Serial.print(" c = ");
    Serial.print((int)round(1.8*temperature_sensor_value+32));
    Serial.print(" f = ");
    Serial.print(",");
    Serial.print("Humidity = ");
    Serial.print(humidity_sensor_value);
    Serial.print(" % ");
    Serial.print(",");
    Serial.print("Light Level = ");
    Serial.print(light_sensor_value);
    Serial.print(",");
    Serial.print("Gas Level = ");
    Serial.print(gas_sensor_value);
    Serial.print(",");
    Serial.print("Air Pressure = ");
    Serial.print(air_pressure_sensor_value);
    Serial.print(",");
    Serial.print("Altitude = ");
    Serial.print(altitude_sensor_value);
    Serial.print(",");
    Serial.print("Sea Level Pressure = ");
    Serial.print(sealevel_pressure_sensor_value);
    
    Serial.println();
    delay(5000);
}
