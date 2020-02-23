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

#ifndef lib_flo_h
#define lib_flo_h

#include <stdint.h>

//change name with the type of the required sensor
typedef float lib_flo_flow_t;
typedef lib_flo_flow_t lib_flo_reading_t;
typedef float lib_flo_factor_t;

typedef struct lib_flo_params_t {
  uint8_t magic_number;
  lib_flo_factor_t flow_factor;
}lib_flo_params_t;


// add any missing cmds
typedef enum lib_flo_cmd_t {
                           flo_read,
                           flo_cal_factor,
                           flo_cal_get,
                           flo_cal_clear,
                           flo_reset,
} lib_flo_cmd_t;

void lib_flo_init(lib_flo_params_t *params_struct);
void lib_flo_cmd(lib_flo_cmd_t command, void *output_buffer);

#endif
