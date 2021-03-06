/*
 * Project Particle_Temp_To_DeviceCloud

 */

#include "Grove_Temperature_And_Humidity_Sensor.h"

//Temperature and Humidity Sensor
DHT sensor(D2);
String temp;
String hum;

// setup() runs once, when the device is first turned on.
void setup()
{

  //Temperature and Humidity Sensor
  Serial.begin(9600);
  sensor.begin();
}

// loop() runs over and over again (delay duration can be manipulated in the Particle App)
void loop()
{

  //get sensor data
  temp = String(sensor.getTempCelcius());
  hum = String(sensor.getHumidity());

  //Particle webhook Thingspeak
  Particle.publish("thingspeak", temp, PRIVATE);

  //wait for 30 seconds
  delay(30 * 1000);
}
