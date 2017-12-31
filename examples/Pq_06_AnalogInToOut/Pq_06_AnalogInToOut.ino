/**
 * PqAnalogInToOut
 * Directly sends smoothed analog input signal to pwm output.
 *
 * The circuit:
 * - Potentiometer attached to analog input 0 center pin of the potentiometer
 *   to the analog pin: one side pin (either one) to ground the other side pin to +5V
 * - LED anode (long leg) attached to analog (PWM) output 9
 * - LED cathode (short leg) attached to ground
 *
 * Created in 2016 by Sofian Audry
 *
 * This example code is in the public domain.
 */
#include <Plaquette.h>

// The analog input.
AnalogIn in; // default on pin A0

// The LED.
AnalogOut led(9);

void begin() {
  // Smooth input value by a factor of 0.01.
  // HINT: try different smoothing values to gauge the difference.
  in.smooth(0.01);
}

void step() {
  // Just send input to output.
  in >> led;
}