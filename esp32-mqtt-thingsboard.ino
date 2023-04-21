#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "your_wifi_network_name";
const char* password = "your_wifi_network_password";
const char* mqttServer = "your_mqtt_broker_address";
const int mqttPort = 1883;
const char* mqttUser = "your_mqtt_username";
const char* mqttPassword = "your_mqtt_password";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  sendData();
  delay(1000);
}

void sendData() {
  char data[50];
  sprintf(data, "{\"temperature\": %d, \"humidity\": %d}", random(15, 25),random(15, 25));
  client.publish("v1/devices/me/telemetry", data);
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
      Serial.println("Connected to MQTT");
    } else {
      Serial.print("Failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
