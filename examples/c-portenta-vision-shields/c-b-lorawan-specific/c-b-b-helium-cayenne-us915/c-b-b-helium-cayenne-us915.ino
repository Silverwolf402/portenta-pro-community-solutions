/*
  Helium Send And Receive
  This sketch demonstrates how to send and receive data with the MKR WAN 1300/1310 LoRa module.
  This example code is in the public domain.
  note: Helium must be setup for what it does with the CayenneLPP encoded data
*/

#include <MKRWAN.h>
#include <CayenneLPP.h>


LoRaModem modem;
CayenneLPP lpp(51);
bool connected = false;

// Please enter your sensitive data in the Secret tab or arduino_secrets.h
// Note: Best to have the App_Device hard coded. Run the program once to see the value.
//#include "arduino_secrets.h"
#define SECRET_APP_EUI "0000000000000000"
#define SECRET_APP_KEY "0000000000000000000000000000000"


String appEui = SECRET_APP_EUI;   // just strings of the above 
String appKey = SECRET_APP_KEY;





void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LEDR,OUTPUT);
  pinMode(LEDG,OUTPUT);
  pinMode(LEDB,OUTPUT);
  digitalWrite(LEDR, HIGH); // new boards HIGH = off
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, HIGH);
  
  //while (!Serial);       // don't wait for serial
  
  Serial.println("Wait 4");
  delay(3000);             // delay instead, so it works when disconnected
  digitalWrite(LEDG, HIGH);// allows time to connect serial monitor

  Serial.println("Wait 3");
  delay(3000);       
  digitalWrite(LEDG, LOW);
 
  Serial.println("Wait 2");
  delay(3000);       
  digitalWrite(LEDG, HIGH);

  Serial.println("Wait 1");
  delay(3000);       
  digitalWrite(LEDG, LOW);



  
  // change this to your regional band (eg. US915, AS923, ...)
  if (!modem.begin(US915)) {
    Serial.println("Failed to start module");
    while (1) {}
  };

  
  Serial.print("Your module version is: ");
  Serial.println(modem.version());
  Serial.print("Your device EUI is: ");
  Serial.println(modem.deviceEUI());

  myPrintMask();
  delay(3000);
  Serial.println("Now Disabling all channels and enable channel 1 only for Helium ");

  modem.disableChannel(0);
  modem.enableChannel(1);    // only one enabled for Helium
  modem.disableChannel(2);
  modem.disableChannel(3);
  modem.disableChannel(4);
  modem.disableChannel(5);
  modem.disableChannel(6);
  myPrintMask(); 
  delay(3000);
  myPrintMask();
  Serial.println("Now Joining the Helium Network ");


 
}

void loop() {

  while (!connected) {
    Serial.println("trying to reconnect");
    digitalWrite(LEDR, LOW); // new boards HIGH = off
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
    connected = modem.joinOTAA(appEui, appKey);
    delay(5000);    
    digitalWrite(LEDR, HIGH); // new boards HIGH = off
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
    delay(1000);
  }

  lpp.reset();
  float x = rand() / 10000000.0; //analogRead(A0)
  lpp.addTemperature(1, x); 

   

  
  Serial.println();
  Serial.println("Sending:" + String(x, 1));

  
  Serial.println();

  int err;
  modem.beginPacket();
  modem.write(lpp.getBuffer(), lpp.getSize());
  err = modem.endPacket(true);
  if (err > 0) {
    Serial.println("Message sent correctly!");
    digitalWrite(LEDR, HIGH); // new boards HIGH = off
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, HIGH);
  } else {
    Serial.println("Error sending message :(");
    Serial.println("(you may send a limited amount of messages per minute, depending on the signal strength");
    Serial.println("it may vary from 1 message every couple of seconds to 1 message every minute)");
    digitalWrite(LEDR, LOW); // new boards HIGH = off
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);
  }
  delay(1000);
  if (!modem.available()) {
    Serial.println("No downlink message received at this time.");
    return;
  }
  char rcv[64];
  int i = 0;
  while (modem.available()) {
    rcv[i++] = (char)modem.read();
  }
  Serial.print("Received: ");
  for (unsigned int j = 0; j < i; j++) {
    Serial.print(rcv[j] >> 4, HEX);
    Serial.print(rcv[j] & 0xF, HEX);
    Serial.print(" ");
  }
  Serial.println();
  digitalWrite(LEDR, HIGH); // new boards HIGH = off
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, LOW);
  delay(30000);  // delay 30 seconds for testing
}



void myPrintMask(){
 
  delay(30);
  Serial.println("Your module version is: " + String(modem.version()) ); 
  delay(30);
  Serial.println("getDataRate: " + String(modem.getDataRate()) );
  delay(30);
  Serial.println("getADR: " + String(modem.getADR()) );
  Serial.println("getRX2Freq: " + String(modem.getRX2Freq()) );
  Serial.println("getRX2DR(): " + String(modem.getRX2DR()) );
   
  Serial.println("getFCU: " + String(modem.getFCU()) );
  Serial.println("getFCD: " + String(modem.getFCD()) );
  delay(30);
  Serial.println("getChannelMask: " + String(modem.getChannelMask()));
  delay(30);
  
  Serial.println("isChannelEnabled(0): " + String(modem.isChannelEnabled(0)));
  delay(30);
  Serial.println("isChannelEnabled(1): " + String(modem.isChannelEnabled(1)));
  delay(30);
  Serial.println("isChannelEnabled(2): " + String(modem.isChannelEnabled(2)));
  delay(30);
  Serial.println("isChannelEnabled(3): " + String(modem.isChannelEnabled(3)));
  delay(30);
  Serial.println("isChannelEnabled(4): " + String(modem.isChannelEnabled(4)));
  delay(30);
  Serial.println("isChannelEnabled(5): " + String(modem.isChannelEnabled(5)));
  delay(30);
  Serial.println("isChannelEnabled(6): " + String(modem.isChannelEnabled(6)));
  delay(30);
  Serial.println("-------------------------------");
}
