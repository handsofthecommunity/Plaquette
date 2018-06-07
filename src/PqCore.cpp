/*
 * PqCore.cpp
 *
 * (c) 2015 Sofian Audry        :: info(@)sofianaudry(.)com
 * (c) 2015 Thomas O Fredericks :: tof(@)t-o-f(.)info
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "PqCore.h"

#include <float.h>

uint8_t Plaquette::_nUnits = 0;
PqUnit* Plaquette::_units[PLAQUETTE_MAX_UNITS];

float Plaquette::_seconds = 0;
float Plaquette::_sampleRate = FLT_MAX;
// float Plaquette::_secondsPerStep = 1.0f / PLAQUETTE_DEFAULT_SAMPLE_RATE;
float Plaquette::_targetSampleRate = 0;
unsigned long Plaquette::_nSteps = 0;
bool Plaquette::_firstRun = true;

void Plaquette::preBegin() {
  // Initialize serial.
  Serial.begin(PLAQUETTE_SERIAL_BAUD_RATE);

  // Initialize variables.
  _seconds = 0;
  _sampleRate = FLT_MAX;
  _targetSampleRate = 0;
  _nSteps = 0;
  _firstRun = true;

  // Initialize all components.
  for (uint8_t i=0; i<_nUnits; i++) {
    _units[i]->begin();
  }
}

void Plaquette::postBegin() {
  // Start timer.
  _seconds = seconds(true);
}

  }
}

void Plaquette::add(PqUnit* component) {
  for (uint8_t i=0; i<_nUnits; i++) {
		if (_units[i] == component)
			return; // do not add existing component
	}
  if (_nUnits < PLAQUETTE_MAX_UNITS) {
    _units[_nUnits++] = component;
  }
}

float Plaquette::seconds(bool realTime) {
  return realTime ? (micros() / 1e6f) : _seconds;
}

bool Plaquette::autoSampleRate() { return (_targetSampleRate <= 0); }

void Plaquette::enableAutoSampleRate() {
  _targetSampleRate = 0;
}

void Plaquette::sampleRate(float sampleRate) {
  _targetSampleRate = max(sampleRate, FLT_MIN);
}

//float seconds(bool realTime) { return Plaquette::seconds(); }
unsigned long nSteps() { return Plaquette::nSteps(); }
void sampleRate(float sampleRate) { Plaquette::sampleRate(sampleRate); }
float sampleRate() { return Plaquette::sampleRate(); }

PqUnit::PqUnit() {
  Plaquette::add(this);
}

bool  PqUnit::analogToDigital(float f) { return (f >= 0.5); }
float PqUnit::digitalToAnalog(bool  b) { return (b ? 1.0f : 0.0f); }
