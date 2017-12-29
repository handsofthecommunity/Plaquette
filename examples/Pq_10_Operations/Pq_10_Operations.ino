/**
 * Pq_SerialOut
 * Demonstrates the different kinds of mathematical and logical operations available with
 * Plaquette objects.
 *
 * Created in 2017 by Sofian Audry
 *
 * This example code is in the public domain.
 */
 #include <Plaquette.h>

// Analog input.
AnalogIn in; // defaults on pin A0

// Digital input.
DigitalIn button(2);

// Analog output.
AnalogOut led(9);

SineOsc oscillator;      // main sine oscillator
SineOsc modulator(10.0); // sine oscillator with period of 10 sec used to modulate oscillator

void begin() {}

void step() {
  // if button is pressed OR if input signal is big enough then use first oscillator
  if (button || in > 0.2)
    0 >> led; // another way to write "led.off()"
  // else modulate by changing the period between [0.5,2.5]
  else
    oscillator.period(0.5 + 2*modulator) >> led;
}