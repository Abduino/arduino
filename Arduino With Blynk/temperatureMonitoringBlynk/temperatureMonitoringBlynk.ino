#define BLYNK_TEMPLATE_ID "TMPLrW1a0DoF"
#define BLYNK_DEVICE_NAME "haramaya"
#define BLYNK_AUTH_TOKEN "xclVeXr8gS_SQrH6MtQh6btHdqdQOviP"
#define BLYNK_PRINT Serial


#include "ESP8266_Lib.h"
#include "BlynkSimpleShieldEsp8266.h"
#include "WiFiEsp.h"
#include "dht.h"

dht DHT;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "D-Link";
char pass[] = "hilu3343";
int status = WL_IDLE_STATUS;
int reqCount = 0; 


#include <SoftwareSerial.h>
SoftwareSerial softserial(4, 5); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&softserial);

#define DHTPIN 13
#define DHTTYPE DHT11     // DHT 11

BlynkTimer timer;

void sendSensor()
{
  int chk = DHT.read11(DHTPIN);
  float h = DHT.temperature;
  float t = DHT.humidity; // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V0, h);
  Blynk.virtualWrite(V1, t);
}


void setup()
{
    Serial.begin(9600);
  // initialize serial for ESP module
    softserial.begin(115200);

  softserial.begin(9600);
  // initialize ESP module
  WiFi.init(&softserial);
  // Debug console
  Serial.begin(9600);
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");

  delay(10);

  Blynk.begin(auth, wifi, ssid, pass, "blynk.cloud", 80);
  
  

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
