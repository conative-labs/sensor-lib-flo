/*
  Copyright (C) 2020 Conative Labs
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program. If not, see <https://www.gnu.org/licenses/>
*/

#ifndef lib_flo_config_h
#define lib_flo_config_h

typedef unsigned long mili_time_t;
static volatile unsigned int pulses_counter;

ISR_INTERRUPT(pulses_counter_callback){ // external interrupt service routine
  pulses_counter ++;
}

static void start_pulses_interrupt(){
}

static void stop_pulses_interrupt(){
}

static void mili_delay(unsigned long value){
}

static mili_time_t get_current_time_mili(){
}

#endif
