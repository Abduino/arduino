#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 8;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
void setup( )
{
  pinMode(A0,INPUT);
Serial.begin( 9600);
}
void loop( )
{
float temperature;
float humidity;
if(dht_sensor.measure(&temperature, &humidity)){
Serial.print( "T = " );
Serial.print( temperature,2);
Serial.print( " deg. C, H = " );
Serial.print( humidity, 2 );
Serial.print( "% " );
int x=temperature;
Serial.print(x);
Serial.println();
}
}
