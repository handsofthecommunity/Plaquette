/*
 * Normalizer.cpp
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

#include "SimpleStats.h"
#include "Normalizer.h"

Normalizer::Normalizer()
  : PqPutter(),
    SimpleStats(),
    _value(0.5f),
    _mean(0.5f),
    _stddev(0.25f)
{}

Normalizer::Normalizer(float mean, float stddev)
	: PqPutter(),
    SimpleStats(),
    _value(mean),
    _mean(mean),
    _stddev(abs(stddev))
{}

float Normalizer::put(float value) {
  return (_value = SimpleStats::update(value) * _stddev + _mean);
}