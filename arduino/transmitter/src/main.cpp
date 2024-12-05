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
Caesar caesar(CAESAR_SHIFT);
void setup() {
  Serial.begin(9600);
  LoRa.begin(9600);
  pinMode(LED, OUTPUT); 
  digitalWrite(LED, HIGH);
} 

void normalTransmit(); 
String removeNewline(String str);
// void normalReceive(); 
// void attacker(); 

void loop() {
  normalTransmit();
  // Serial.println("Hello World");
  delay(10);
}
// đụ má né 2 chân 1 2 ra, lỗi game vl 
void normalTransmit() {
  if (Serial.available()) {
    // String msg = Serial.readStringUntil('\n'); // read until newline
    // // Remove the newline character
    // msg.remove(msg.length() - 1);
    
    // // Allocate memory for the C-string
    // char *msgChar = new char[msg.length() + 1];
    // strcpy(msgChar, msg.c_str());
    
    // // Encrypt the message
    // char *encryptedMsg = caesar.CaesarEncryption(msgChar);
    
    // // Send the encrypted message via Serial and LoRa
    // Serial.write(encryptedMsg);
    // // Serial.write('\n'); // Add newline for Serial output
    // LoRa.write(encryptedMsg);
    
    // // Free the allocated memory
    // delete[] msgChar;
    // delete[] encryptedMsg;

    // read string as char array
    String msg = Serial.readStringUntil('\n');
    msg = removeNewline(msg);
    char *msgChar = new char[msg.length() + 1];
    strcpy(msgChar, msg.c_str());
    char *encryptedMsg = caesar.CaesarEncryption(msgChar);
    Serial.write(encryptedMsg);
    LoRa.write(encryptedMsg);
    char *decryptedMsg = caesar.CaesarDecryption(encryptedMsg);
    Serial.write('\n');
    Serial.write(decryptedMsg);
    delete[] msgChar;
    delete[] encryptedMsg;
  }
}

String removeNewlineAfter(String str){
  if (str.charAt(str.length() - 1) == ' ') return str.substring(0, str.length() - 1);
  else return str;
}

// void normalReceive(){
//   if (LoRa.available()){
//     char *msgChar = new char[100];
//     LoRa.readBytesUntil('\n', msgChar, 100);
//     Serial.println(msgChar);
//     delete[] msgChar;
//   }
// }

// // Assuming that the attacker is using the default OOBE LoRa frequency settings. 
// void attacker(){
//   if (Serial.available()){
//     String msg = Serial.readStringUntil('\n');
//     LoRa.println(msg);
//   }
//   if (LoRa.available()){
//     String msg = LoRa.readStringUntil('\n');
//     Serial.println(msg);
//   }
// }