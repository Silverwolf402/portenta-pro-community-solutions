/*  
 *   a-servo.ino
 *
 *
 * GNU GENERAL PUBLIC LICENSE
 * Use at your own risk.
 ************************************************ Important stuff if needed ****************************************
 *
 * You need both a servo motor and a power supply correct for that servo motor! Best to use an external battery
 * even if you have a 3.3 V Servo motor.
 *
 *
 * MUST HAVE A 6 VOLT EXTERNAL BATTERY
 * Note: REMEMBER 2 WIRES GO TO THE SERVO GROUND (Battery Neg and Board GND)
 * Servos run from 0 to 180 degrees, test 20 - 160 first
 * 
 * servo red to 6V battery positive
 * servo ground (brown or black) to 6V battery negative
 * servo ground (brown or black) to board GND
 * servo controller (orange or the other color) to board PWM pin D5   
 * 
 * Note For PWM pins check your boards Pinout diagram.
 * 
 ********************************************************** end ****************************************************
 *
 *  By Jeremy Ellis twitter @rocksetta
 *  Webpage http://rocksetta.com
 *  Arduino High School Robotics Course at
 *  https://github.com/hpssjellis/arduino-high-school-robotics-course
 * 
 *  Update Aug 7th, 2020
 * 
 */

#include <Arduino.h>  // only needed for https://platformio.org/
#include <Servo.h>

Servo myServo_D2;

void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  myServo_D2.attach(D2);   // D2 should do PWM on Portenta

}

void loop() {
 
  digitalWrite(LED_BUILTIN, LOW); // Portenta onboard LED on    
    
  myServo_D2.write(20);           // servo at 20 degrees try 0
  delay(2000);
    
  myServo_D2.write(160);         // servo at 160 degrees try 180
  delay(2000);

  myServo_D2.write(90);          // servo at 90 degrees
  delay(2000);   
    
    
  for (int myLoop = 20; myLoop <= 160; myLoop++){
    myServo_D2.write(myLoop);
    delay(25);  // short delay 25 ms
  }

  digitalWrite(LED_BUILTIN, HIGH);     // Portenta onboard LED off
  delay(5000);            // 5 second delay

}




/*
* Clickable links for helpful information
* By @rocksetta
* March, 2021
* GNU GENERAL PUBLIC LICENSE
* Use at your own risk.
*
*
*
*  Artduino Pro Links:
*
*  https://store.arduino.cc/usa/portenta-h7
*  https://forum.arduino.cc/index.php?board=148.0
*  https://www.arduino.cc/pro/tutorials/portenta-h7
*
*  Rocksetta links:
* 
*  https://twitter.com/rocksetta
*  https://github.com/hpssjellis/portenta-pro-community-solutions
*  https://github.com/hpssjellis/my-examples-for-the-arduino-portentaH7
*  https://github.com/hpssjellis/arduino-high-school-robotics-course
*  https://www.youtube.com/playlist?list=PL57Dnr1H_egtm0pi-okmG0iE_X5dROaLw
*
*
*
*/
