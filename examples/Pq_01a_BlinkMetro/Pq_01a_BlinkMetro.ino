/**
 * Pq_Metro
 *
 * Turns on and off a light emitting diode (LED) at increasingly long
 * durations.
 *
 * The circuit:
 * - LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 * that's attached to pin 13, so no hardware is needed for this example.
 *
 * Created in 2018 by Sofian Audry
 *
 * This example code is in the public domain.
 */
#include <Plaquette.h>

// The LED.
DigitalOut led(13);

// The timer.
Metro metro(1.0); // period: 1 second

void begin() {}

void step() {
  // Every time the metronome "fires" change LED state.
  if (metro)
    led.toggle();
}
