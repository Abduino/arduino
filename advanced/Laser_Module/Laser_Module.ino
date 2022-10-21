void setup ()
{
pinMode (11, OUTPUT); // define the digital output interface 13 feet
}
void loop () {
digitalWrite (11, HIGH); // open the laser head 
delay (1000); // delay one second
digitalWrite (11, LOW); // turn off the laser head 
delay (1000); // delay one second
}
