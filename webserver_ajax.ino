
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "MARK1"; // Change to your WiFi SSID
const char *password = "Scaredtocompile"; // Change to your WiFi password

AsyncWebServer server(80);
String serialData;

void setup() {
  Serial.begin(115200);
m

  WiFi.softAP(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", "<html><head><meta http-equiv='refresh' content='1'></head><body><h1>Serial Data:</h1><div id='data'></div><script>setInterval(function() { fetch('/getSerialData').then(response => response.text()).then(data => document.getElementById('data').innerHTML = data); }, 1000);</script></body></html>");
  });

  server.on("/getSerialData", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", serialData);
  });

  server.begin();
}

void loop() {
  if (Serial.available() > 0) {
    serialData = Serial.readStringUntil('\n');
    Serial.println("Received serial data: " + serialData);
  }
  //printing incoming serial data from nano to webserver 
}
