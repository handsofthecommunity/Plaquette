/*
 * TriOsc.h
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

#ifndef TRI_OSC_H_
#define TRI_OSC_H_

#include "PqCore.h"

/**
 * Triangle/sawtooth oscillator.
 */
class TriOsc : public PqGetter {
public:
  /**
   * Constructor.
   * @param period the period of oscillation (in seconds)
   * @param width a value in [0, 1] that determines the point at which the wave reaches its maximum point (expressed as a fraction of the period)
   */
  TriOsc(float period=1.0f, float width=0.5f);
  virtual ~TriOsc() {}

  /// Returns value in [0, 1].
  virtual float get() { return _value; }

  /**
   * Sets the period (in seconds).
   * @param period the period of oscillation (in seconds)
   * @return the unit itself
   */
  virtual TriOsc& period(float period);

  /**
   * Sets the frequency (in Hz).
   * @param frequency the frequency of oscillation (in Hz)
   * @return the unit itself
   */
  virtual TriOsc& frequency(float freq) { return period(1/freq); }

  /**
   * Sets the width of the wave.
   * @param width a value in [0, 1] that determines the point at which the wave reaches its maximum point (expressed as a fraction of the period)
   * @return the unit itself
   */
  virtual TriOsc& width(float width);

protected:
  // Core Plaquette methods.
  virtual void setup();
  virtual void update();

  // Current value of the signal.
  float _value;

  // Period (seconds).
  float _period;

  // Tipping-point (in % of period).
  float _width;

  // Start time of each period (in seconds).
  float _startTime;
};

#endif