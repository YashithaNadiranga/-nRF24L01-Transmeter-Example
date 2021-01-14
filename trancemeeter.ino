#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

int y[5];


void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
}

void loop() {



  y[0] = analogRead(A0);
  y[1] = analogRead(A1);
  y[2]= digitalRead(3);
 Serial.println(y[3]);




  //  const int text[] = "Hello World";
  radio.write(&y, sizeof(y));



}
