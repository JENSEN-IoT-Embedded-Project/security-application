#ifndef HCSR04_H
#define HCSR04_H

#include "pico/stdlib.h"
#include "hardware/timer.h"




void echo_irq_callback(uint gpio, uint32_t events);
void init_echo_callback(const uint GPIO_IN);
void send_trigger_pulse(const uint GPIO_OUT,double* distance);


#endif
