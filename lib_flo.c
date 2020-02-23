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

#include "lib_flo.h"

#ifdef TEST
#include "lib_flo_config_test.h"
#else
#include "lib_flo_config.h"
#endif

#define MAGIC_NUMBER_DEFAULT 0x67 // 8 bit random number prefered to be unique, for integrity check of params
#define FLOW_FACTOR_DEFAULT 4.5

static lib_flo_params_t *params;

static void calibration_set_default(void) {
// set the default calibration
	params->flow_factor = FLOW_FACTOR_DEFAULT;
}

static void params_set_default(void) {
	params->magic_number = MAGIC_NUMBER_DEFAULT;
	calibration_set_default();
}

void lib_flo_init(lib_flo_params_t *ext_params){
  params = ext_params;
  if(params->magic_number != MAGIC_NUMBER_DEFAULT)
    params_set_default();
}

static lib_flo_flow_t compute_flow_rate(mili_time_t start_time, mili_time_t end_time, unsigned int pulses){
  return (pulses * (1000.0/(end_time - start_time))) /params->flow_factor;
}

void lib_flo_cmd(lib_flo_cmd_t cmd, void *buffer) {
  lib_flo_flow_t flo_value;
  mili_time_t start,end; 
  switch(cmd) {
  case flo_read: 
#ifndef TEST // to mock pulses
    pulses_counter = 0;
#endif
    start_pulses_interrupt();
    start = get_current_time_mili();
    mili_delay(1000);
    stop_pulses_interrupt();
    end = get_current_time_mili();
    flo_value = compute_flow_rate(start, end, pulses_counter);
    *(lib_flo_flow_t *)buffer = flo_value;
    break;
  case flo_cal_factor:
    params->flow_factor = *(lib_flo_factor_t *) buffer;
    break;
  case flo_cal_get:
    ((uint8_t *)buffer)[0] = 0;
    if(params->flow_factor != FLOW_FACTOR_DEFAULT)
    	((uint8_t *)buffer)[0] = 1;
    break;
  case flo_cal_clear:
    calibration_set_default();
    break;
  case flo_reset:
    params_set_default();
    break;
  }
}
