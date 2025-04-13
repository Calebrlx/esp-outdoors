

Step 1: Arduino Sketch (main.ino):

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <DNSServer.h>

// WiFi AP credentials
const char* ssid = "OutdoorStuff";
const char* password = "outdoor123";

// DNS server setup
DNSServer dnsServer;
AsyncWebServer server(80);

// Captive portal domain
const char* captiveDomain = "outdoors.stuff";

// Setup function
void setup() {
  Serial.begin(115200);
  
  // Initialize SPIFFS
  if (!SPIFFS.begin()) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Configure WiFi Access Point
  WiFi.softAP(ssid, password);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  // DNS server redirecting all queries to the ESP32 IP (Captive portal)
  dnsServer.start(53, "*", WiFi.softAPIP());

  // Serve static files from SPIFFS
  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");

  // API endpoint for inventory data (example)
  server.on("/api/inventory", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/inventory.json", "application/json");
  });

  server.begin();
  Serial.println("Server started.");
}

void loop() {
  dnsServer.processNextRequest();
}








