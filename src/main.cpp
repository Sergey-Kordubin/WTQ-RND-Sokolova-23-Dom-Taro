#include <Arduino.h>
#include <MFRC522.h>
#include <FastCRC.h>




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   // native USB
  Serial1.begin(9600);  // Uart yo RS485
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);
  }

  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
}