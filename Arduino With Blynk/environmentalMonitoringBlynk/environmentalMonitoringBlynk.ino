#define BLYNK_TEMPLATE_ID "TMPL_wuL1bg4"
#define BLYNK_DEVICE_NAME "Sport channel"
#define BLYNK_AUTH_TOKEN "tOfvdAletv2zEin4WGLzDToj6LV9ADNZ"
#define BLYNK_PRINT Serial
#include <Wire.h>
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include<dht.h>
#define DHT11_PIN 2
dht DHT;

const int soil_sensor_pin = A0;
const int light_sensor_pin = A1;
const int gas_sensor_pin = A2; 
const int rain_sensor_pin = 3;


//const int pre_sensor_pin = A4;
//const int pre_sensor_pin = A5;



char ssid[] = "tarik";
char pass[] = "123456789";


 #include <SoftwareSerial.h>
 SoftwareSerial EspSerial(4, 5); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);


BlynkTimer timer;
void sendSensor()
{
   int gas = analogRead(gas_sensor_pin)*100/1024;
   int soil_moisture = analogRead(soil_sensor_pin); 
   //float pressure = bmp.readPressure();
    //float temperature2 =bmp.readTemperature();
    //float altitude= bmp.readAltitude();
    int rain = digitalRead(rain_sensor_pin);
    int light = analogRead(light_sensor_pin);
    int percentValue = 100-map(light, 0, 1023, 0, 100);
    int chk = DHT.read11(DHT11_PIN);
    float   temperature=DHT.temperature;
    float   humidity=DHT.humidity;
  
  int t = temperature;
  int h = humidity;
  
  Blynk.virtualWrite(V0, soil_moisture);
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2,h);
  //Blynk.virtualWrite(V3, pressure);
  Blynk.virtualWrite(V4,gas);
  Blynk.virtualWrite(V5, percentValue);
 // Blynk.virtualWrite(V6,altitude);
   Blynk.virtualWrite(V7,rain);
  
 // Blynk.virtualWrite(V3, millis() / 1000);
  //}
  
  //Blynk.virtualWrite(V1, t);
}




void setup()
{
  // Debug console
  Serial.begin(9600);
  

  delay(10);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass);
  //bmp.begin();
  //if (!bmp.begin()) {
   // Serial.println(F("Could not find a valid BMP180 sensor, check wiring!"));
  //}
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
