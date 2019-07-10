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
