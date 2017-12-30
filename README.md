Plaquette is a user-friendly, modular, signal-centric programming framework for creative physical computing compatible with Arduino.

* **User-friendly**: Allows users to quickly design interactive systems using an expressive language that abstracts away low-level functions.
* **Modular**: Designed using input, output, and filtering units that can be easily interchanged in a plug-and-play fashion.
* **Signal-centric**: Focused on real-time signal processing from inputs to outputs by providing simple data filtering tools for smoothing and normalization.
* **Arduino compatible**: Installed as an Arduino library and provides a replacement for the core Arduino functionalities while remaining fully compatible with Arduino code.

## Getting started

### Step 1: Install Plaquette

If you do not have Arduino installed on your machine you need to [download and install the Arduino IDE](https://www.arduino.cc/en/Main/Software) for your platform.

Once Arduino is installed, please install Plaquette as an Arduino library following [these instructions](https://www.arduino.cc/en/Guide/Libraries).

### Step 2: Your first Plaquette program

We will begin by creating a simple program that will make the built-in LED blink.

### Initialize sketch

Create a new empty sketch.

Include the Plaquette library by typing:
```c++
#include <Plaquette.h>
```

### Create an output unit

Now, we will create a new unit that will allow us to control the built-in LED:

```c++
DigitalOut myLed(13);
```

In this statement, ```DigitalOut``` is the **type** of unit that we are creating. There exist other types of units as we will soon see. ```DigitalOut``` is a type of unit that is attached to one of the many digital outputs on the Arduino board which can be set to one of two states ("on/off", "high/low", "1/0").

The word ```myLed``` is a **name** for the object we are creating.

Finally, ```13``` is a **parameter** of the object ```myLed``` that specifies the *pin* it corresponds to on the board.

In English, the statement would thus read as: "Create a unit named ```myLed``` of type ```DigitalOut``` on pin ```13```."

### Create an input unit

We will now create another unit that will generate a signal which will be sent to the LED to make it blink. To this effect, we will use the ```SquareOsc``` unit type which generates a [square wave](https://en.wikipedia.org/wiki/Square_wave) oscillating between "on/high/one" and "off/low/zero" at a regular period of 2.0 seconds and a [duty-cycle](https://en.wikipedia.org/wiki/Duty_cycle) of 50%:

```c++
SquareOsc myOsc(2.0, 0.5);
```

### Create the begin() function

Each Plaquette sketch necessitates the declaration of two functions: ```begin()``` and ```step()```.

Function ```begin()``` is called only once at the beginning of the sketch (just like the [setup()](https://www.arduino.cc/reference/en/language/structure/sketch/setup/) function in Arduino). In our case, we do not to perform any special configuration at startup so we will leave the ```begin()``` function empty:

```c++
void begin() {}
```

### Create the step() function

The ```step()``` function is called repetitively and indefinitely during the course of the program (like the [loop()](https://www.arduino.cc/reference/en/language/structure/sketch/loop/) function in Arduino).

Here, we need to send the signal generated by the ```myOsc``` input unit to the ```myLed``` output unit. We will do this using Plaquette's special ```>>``` operator:

```c++
void step() {
  myOsc >> myLed;
}
```

In plain English, the statement ```myOsc >> myLed``` reads as: "Take the value generated by ```myOsc``` and put it in ```myLed```."

### Upload sketch

Upload your sketch to the Arduino board. You should see the LED on the board blinking once every two seconds at a regular pace.

Hurray!!!

### Full code

```c++
#include <Plaquette.h>

DigitalOut myLed(13);

SquareOsc myOsc(2.0, 0.5);

void begin() {}

void step() {
  myOsc >> myLed;
}
```

### Experiments

#### Period and duty

Try changing the *period* and/or *duty-cycle* parameters in the square wave unit construction. What happens?

```c++
SquareOsc myOsc(<period>, <duty cycle>);
```

#### Adding and multiplying

Add another oscillator with a different period and duty cycle: multiply their values and send the result to the LED.

```c++
SquareOsc myOsc2(<period>, <duty cycle>);
// ...
void step() {
  (myOsc * myOsc2) >> myLed;
}
```

Try adding their values instead: what do you see?

#### Use a conditional

Add a third oscillator that will "switch" between the two oscillators every 5 seconds using an [if...else](https://www.arduino.cc/reference/en/language/structure/control-structure/if/) statement.

```c++
// NOTE: omitting the duty-cycle parameter results in default value (0.5)
SquareOsc mySwitcher(5.0); 
// ...
void step() {
  if (mySwitcher)
    myOsc >> myLed;
  else
    myOsc2 >> myLed;
}
```

NOTE: You can rewrite this expression in a more compact way using the [? : conditional operator](https://www.tutorialspoint.com/arduino/arduino_conditional_operator.htm):
```c++
void step() {
  (mySwitcher ? myOsc : myOsc2) >> myLed;
}
```

## Credits

Developers:
* Sofian Audry • [Website](http://sofianaudry.com) • [GitHub](https://github.com/sofian)
* Thomas Ouellet Fredericks • [Website](http://www.t-o-f.info) • [GitHub](https://github.com/thomasfredericks)

Plaquette's base source code was produced as part of a research project at [labXmodal](http://xmodal.hexagram.ca). A special thanks to [Chris Salter](http://chrissalter.com) for his support.

## License

Plaquette is distributed under the [Gnu General Public License v 3.0](https://www.gnu.org/licenses/gpl-3.0.en.html).

The text of the Plaquette guide is licensed under a [Creative Commons Attribution-ShareAlike 3.0 License](https://creativecommons.org/licenses/by-sa/3.0/). Code samples in the guide are released into the public domain.
