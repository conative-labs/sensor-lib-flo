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
