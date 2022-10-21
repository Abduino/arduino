
int PUMPG = 12;
int PUMPR = 13; 
//output pin connected to AC water pump
int sensor = 8; // input pin connected to soil moisture
int val; // to read signal from sensor

void setup() {
Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); 
  pinMode(12, OUTPUT); 
  //use pimode function to set pin 13 as output device
  pinMode(8, INPUT); //use pimode function to set pin 13 as input device

  
  Serial.println("** program start **");
  delay(1000);

}

void loop() {
   Serial.println("##########the loop is started ######");
  digitalWrite(13, LOW);
digitalWrite(12, LOW);

  int SensorValue = analogRead(8);
 Serial.println("the value of the sensor is = "); Serial.println(SensorValue);Serial.print(" --");
  // put your main code here, to run repeatedly:
  val = digitalRead(8); //take input from soil moisture
  if (val == LOW)
  {
   
      digitalWrite(13, HIGH);
    Serial.println("the value of the sensor is = "); Serial.println(SensorValue);Serial.print(" and its not humid");

  }
  else
  {

    digitalWrite(12, HIGH);
   Serial.println("the value of the sensor is = "); Serial.println(SensorValue);Serial.print(" and its humid");

  }
  delay(3000);

}



//alchol sensor 

/*******
 
 All the resources for this project:
 https://www.hackster.io/Aritro

*******/

int redLed = 13;
int greenLed = 12;
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 400;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);

  digitalWrite(buzzer,LOW);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
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
  delay(100);
}






// flame sensor
int vib_pin=7;
int vib_pinAnalog=A0;
int led_pinR=13;
int led_pinB=12;
int buzzer = 10;

void setup() {
  pinMode(vib_pin,INPUT);
  pinMode(led_pinR,OUTPUT);
  pinMode(led_pinB,OUTPUT);
  pinMode(buzzer, OUTPUT);
   digitalWrite(buzzer,LOW);
  Serial.begin(9600);
}

void loop() {
  int valDigital;
  int valAnalog;
  valDigital=digitalRead(vib_pin);
  valAnalog=analogRead(vib_pinAnalog);
  if(valDigital==1)
  {
    digitalWrite(led_pinB,HIGH);
    Serial.println("the value is digital" + vib_pin);
    Serial.println("the value is" + vib_pinAnalog);

    digitalWrite(buzzer,HIGH);
   }
   else
   {
   digitalWrite(led_pinR,HIGH);

   }
    
}









#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
    Serial.print("Read DHT11 failed.");
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" %");
  
  // DHT11 sampling rate is 1HZ.
  delay(1000);
}



#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }
  
  Serial.print("Sample RAW Bits: ");
  for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);
    if (i > 0 && ((i + 1) % 4) == 0) {
      Serial.print(' ');
    }
  }
  Serial.println("");
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
  
  // DHT11 sampling rate is 1HZ.
  delay(1000);
}



//www.elegoo.com
//2016.06.13

int  sensorPin  =  A0;     // select the input  pin for  the potentiometer 
int  ledPin  =  13;   // select the pin for  the LED
int  sensorValue =  0;  // variable to  store  the value  coming  from  the sensor

void setup()
{
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}
void loop(){
sensorValue =  analogRead(sensorPin);
Serial.println("the value is = ");
Serial.println(sensorValue);
//digitalWrite(ledPin,  HIGH); 
//delay(sensorValue); 
//digitalWrite(ledPin,  LOW);
//delay(sensorValue);
Serial.println(sensorValue,  DEC);
delay(3000);
}
