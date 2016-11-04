/**
 * Button
 *
 * Turns on and off a light emitting diode(LED) connected to digital
 * pin 13, when pressing a pushbutton attached to pin 2.
 *
 * The circuit:
 * - LED attached from pin 13 to ground
 * - pushbutton attached to pin 2 from ground
 * Note: on most Arduinos there is already an LED on the board
 * attached to pin 13.
 *
 * created 2005
 * by DojoDave <http://www.0j0.org>
 * modified 30 Aug 2011
 * by Tom Igoe
 * modified 3 Nov 2016
 * by Sofian Audry
 *
 * This example code is in the public domain.
 *
 * Based on the following code:
 * http://www.arduino.cc/en/Tutorial/Button
 */
#include <Plaquette.h>

DigitalOut led; // defaults on pin 13
DigitalIn button(2); // defaults to INTERNAL_PULLUP

void begin() {
  button.smooth(); // debounce button
}

void run() {
  // Send button value to LED.
  button >> led;
}
