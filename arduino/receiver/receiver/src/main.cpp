#include <Arduino.h>
#include <SoftwareSerial.h>
#include "header.h"
// pin scheme
// RX = 0
// TX = 1
// M0 = GND
// M1 = GND
// VCC = 5V
// GND = GND


SoftwareSerial LoRa(RX, TX);

void setup() {
  Serial.begin(9600);
  LoRa.begin(9600);
  pinMode(LED, OUTPUT); 
  digitalWrite(LED, HIGH);
}

void normalTransmit(); 
void normalReceive(); 
void attacker(); 

void loop() {
  normalReceive();
}

void normalTransmit(){
  if (Serial.available()){
    String msg = Serial.readStringUntil('\n'); // read until newline
    char *msgChar = new char[msg.length() + 1];
    strcpy(msgChar, msg.c_str());
    LoRa.write(msgChar);
    delete[] msgChar;
  }
}

void normalReceive(){
  if (LoRa.available()){
    char *msgChar = new char[100];
    LoRa.readBytesUntil('\n', msgChar, 100);
    Serial.println(msgChar);
    delete[] msgChar;
  }
}

// Assuming that the attacker is using the default OOBE LoRa frequency settings. 
void attacker(){
  if (Serial.available()){
    String msg = Serial.readStringUntil('\n');
    LoRa.println(msg);
  }
  if (LoRa.available()){
    String msg = LoRa.readStringUntil('\n');
    Serial.println(msg);
  }
}