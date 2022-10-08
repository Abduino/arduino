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
