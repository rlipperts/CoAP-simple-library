#include <WiFi.h>
#include <WiFiUdp.h>
#include <coap-simple.h>

const char* ssid     = "Mi-A3";
const char* password = "password";
std::thread *t;

// CoAP client response callback
void callback_response(CoapPacket &packet, IPAddress ip, int port);

// CoAP server endpoint url callback
void callback_server(CoapPacket &packet, IPAddress ip, int port);

// UDP and CoAP class
WiFiUDP udp;
Coap coap(udp, t);

// CoAP client response callback
void callback_response(CoapPacket &packet, IPAddress ip, int port) {
//  Serial.println("Received an ACK!");
  
  char p[packet.payloadlen + 1];
  memcpy(p, packet.payload, packet.payloadlen);
  p[packet.payloadlen] = NULL;
  
//  Serial.println(p);
}

void setup() {
  Serial.begin(9600);
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }

  Serial.println("");
  Serial.println("Client: WiFi connected");
  Serial.println("Client IP address: ");
  Serial.println(WiFi.localIP());

  // client response callback.
  // this endpoint is single callback.
  Serial.println("Setup Client Response Callback");
  coap.response(callback_response);

  // start coap server/client
  coap.start();
}

void loop() {
  // send GET or PUT coap request to CoAP server.
  // To test, use libcoap, microcoap server...etc
  // int msgid = coap.put(IPAddress(10, 0, 0, 1), 5683, "light", "1");
  Serial.println("");
  Serial.println("Send Request");
  int msgid = coap.get(IPAddress(192, 168, 43, 215), 5683, "server");

  delay(1000);
  coap.loop();
  delay(9000);
}
