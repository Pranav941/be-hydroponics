/*
*/

#include "DHT.h" 

#define DHTPIN 2
#define DHTTYPE DHT11

int Relaypin= 3; // Define input pin for relay

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));
  dht.begin();
  pinMode(Relaypin, OUTPUT); // Define the Relaypin as output pin
}

void loop() {
  // put your main code here, to run repeatedly:
  // EVERY_N_SECONDS(2) { // Min 2000 are required for DHT11 to update precisely
  float temp = dht.readTemperature();
  Serial.println(temp);
  digitalWrite(Relaypin, HIGH); // Sends high signal 
  delay(1000); // Waits for 1 second
  digitalWrite(Relaypin, LOW); // Makes the signal low
  delay(1000); // Waits for 1 second
}
