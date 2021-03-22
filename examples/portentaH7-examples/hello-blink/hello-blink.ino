/* hello-blink.ino for the Portenta H7
*  Turns on the blue LED on for one second, then off for three seconds, repeatedly.
*  also checks if Serial Printing is working
*  July 22nd, 2020
*  by Jeremy Ellis
*  Twitter @rocksetta
*  Website https://www.rocksetta.com
*/

void setup() {
  Serial.begin(115200);
  pinMode(LEDB, OUTPUT);   // LEDB = blue, LEDG or LED_BUILTIN = green, LEDR = red 
  // while (!Serial);  // Please don't do this it messes up beginners  sa it taps your program until a serial prot is conected
}

void loop() {
  Serial.println("Serial print works on the M7 core only.");
  digitalWrite(LEDB, LOW);   // internal LED LOW = on
  delay(1000);               // wait for a second
  digitalWrite(LEDB, HIGH);  
  delay(3000);               
}

/*
* Clickable links to helpful information
* By @rocksetta
* March, 2021
*
*
*
*
* https://store.arduino.cc/usa/portenta-h7
* https://www.arduino.cc/pro/tutorials/portenta-h7
* https://github.com/hpssjellis/my-examples-for-the-arduino-portentaH7
* https://github.com/hpssjellis/portenta-pro-community-solutions
*/



