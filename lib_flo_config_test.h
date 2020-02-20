#ifndef lib_flo_config_h
#define lib_flo_config_h

typedef unsigned long mili_time_t;
volatile unsigned int pulses_counter;

void start_pulses_interrupt();
void stop_pulses_interrupt();
void mili_delay(unsigned long value);
mili_time_t get_current_time_mili();

#endif
