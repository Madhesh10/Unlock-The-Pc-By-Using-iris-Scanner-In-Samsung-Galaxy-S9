#include <ESP8266WiFi.h>

const char* ssid = "YourWiFiSSID";  // Change to your Wi-Fi SSID
const char* password = "YourWiFiPassword"; // Change to your Wi-Fi Password

WiFiServer server(80);  // Start a server on port 80

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi connected.");
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("UNLOCK") != -1) {
      Serial.println("Unlock command received!");
      // Send signal to PC
      Serial.write("UNLOCK");
    }
    
    client.stop();
  }
}
