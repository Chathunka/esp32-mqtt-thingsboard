# esp32-mqtt-thingsboard

ESP32 MQTT Thingsboard Demo:

This is a simple demo project that sends temperature and humidity data from an ESP32 device to the Thingsboard IoT platform using MQTT protocol.

Getting Started:

Prerequisites:

To run this project, you will need the following:

An ESP32 development board

Arduino IDE

PubSubClient library

WiFi library

Installing:

Connect your ESP32 board to your computer using a USB cable.

Open the Arduino IDE and select your board from the Tools -> Board menu.

Install the required libraries by going to Sketch -> Include Library -> Manage Libraries and searching for PubSubClient and WiFi.

Copy the code from the mqtt-thingsboard-demo.ino file and paste it into a new sketch in the Arduino IDE.

Replace the values of the ssid, password, mqttServer, mqttPort, mqttUser, and mqttPassword variables with your own Wi-Fi network and MQTT broker details.

Upload the code to your ESP32 board by clicking the Upload button in the Arduino IDE.

Usage:

Open the serial monitor by clicking Tools -> Serial Monitor in the Arduino IDE.

You should see the ESP32 connecting to the Wi-Fi network and MQTT broker.

Once connected, the ESP32 will send temperature and humidity data to the v1/devices/me/telemetry topic in JSON format.

You can view the data on the Thingsboard platform by creating a dashboard and adding a widget that subscribes to the v1/devices/me/telemetry topic.

Contributing:

Contributions to this project are welcome. Feel free to fork this repository and make changes as you see fit.

License:

This project is licensed under the MIT License - see the LICENSE file for details.
