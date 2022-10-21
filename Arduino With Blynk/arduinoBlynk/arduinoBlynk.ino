#define BLYNK_TEMPLATE_ID "TMPLrW1a0DoF"
#define BLYNK_DEVICE_NAME "IoT Based Environmental Monitoring System"
#define BLYNK_AUTH_TOKEN "hmvVoqyG5k9Nr2eNIC9puiFiReWNxzt5"
#define BLYNK_PRINT Serial


#include "ESP8266_Lib.h"
#include "BlynkSimpleShieldEsp8266.h"
#include "WiFiEsp.h"
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "D-Link";
char pass[] = "hilu3343";
int status = WL_IDLE_STATUS;
int reqCount = 0; 
// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial softserial(4, 5); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&softserial);

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

  //Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  Blynk.begin(auth, wifi, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
