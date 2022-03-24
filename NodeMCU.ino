#include <ESP8266WiFi.h>
#include <FastLED.h>
#include <DHT.h>

DHT dht(0, DHT11);
String apiKey = "0M544HH3UJQ0FVZC";     //  Enter your Write API key from ThingSpeak
 
const char *ssid =  "SSH";     // replace with your wifi ssid and wpa2 key
const char *pass =  "NA856519";
const char* server = "api.thingspeak.com";

float temp,humi,hic;
char buf[30];
String str3,str4;

WiFiClient client;

void setup() {
  dht.begin();
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    // wait for serial port to connect. Needed for native USB port only
  }
  delay(3000);
  Serial.println("Connecting to ");
       Serial.println(ssid);
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
}

void loop() { // run over and over
    EVERY_N_SECONDS(5) {
      if (Serial.available()) {
        str3 = Serial.readString();
        if(str3.length()) {
          str4 = str3;
         
          str4 = str4.substring(1, 6);
          str3 = str3.substring(7,12);
          
          str4.toCharArray(buf,5); // To char array = 31.60
          temp = atof(buf);
          str3.toCharArray(buf,5);
          humi = atof(buf);
          hic = dht.computeHeatIndex(temp, humi, false); // In Celcius   
          Serial.print("Temperature - ");  Serial.println(temp);
          Serial.print("HumidityIN% - ");  Serial.println(humi);
          Serial.print("Heat Index  - ");  Serial.println(hic);
        }
      }
    }
    EVERY_N_SECONDS(15) {
      if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(temp);
                             postStr +="&field2=";
                             postStr += String(humi);
                             postStr +="&field3=";
                             postStr += String(hic);
                             
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             Serial.print(temp);
                             Serial.print(" degrees Celcius, Humidity: ");
                             Serial.print(humi);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
    Serial.println("Waiting...");
    }
}
