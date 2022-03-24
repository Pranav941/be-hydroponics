/* GitHub : https://github.com/Pranav941/be-hydroponics
*/

#include <DHT.h>
#include <FastLED.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define growLight 3
#define airiator 5

float temp,humi;
String str1;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
  pinMode(growLight, OUTPUT); // Define the Relaypin as output pin
  pinMode(airiator, OUTPUT); // Define the Relaypin as output pin
}

void loop() {
  EVERY_N_SECONDS(5) { // Min 2000 are required for DHT11 to update precisely
    temp = dht.readTemperature(); // Pass True argument for Farenheit
    humi = dht.readHumidity();
    str1 = "T" + String(temp,2) + "H" + String(humi,2);
    Serial.println(str1);
  }
  EVERY_N_SECONDS(2) { // Min 2000 are required for DHT11 to update precisely
  digitalWrite(growLight, HIGH); // Sends high signal 
  digitalWrite(airiator, LOW); // Makes the signal low
  delay(1000); // Waits for 1 second
  digitalWrite(growLight, LOW); // Makes the signal low
  digitalWrite(airiator, HIGH); // Sends high signal 
  delay(1000); // Waits for 1 second
  }
}
