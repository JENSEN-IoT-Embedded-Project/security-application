#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include <stdio.h>
#include "hcsr04.h"
//volatile "type_qualifire" säger explicit till kompilatorn att alltid läsa den direkt från minnet varje gång den användsdå värdet på variable kan ändras närsomhelst av kod som inte ligger i main tillexempel en callback
volatile absolute_time_t echo_start;
volatile uint64_t echo_duration_us;
volatile bool echo_done = false;
void echo_irq_callback(uint gpio, uint32_t events) {

    if(events & GPIO_IRQ_EDGE_RISE) {
        echo_start = get_absolute_time();
    }
    else if(events & GPIO_IRQ_EDGE_FALL) {
        absolute_time_t echo_end = get_absolute_time();
        echo_duration_us = absolute_time_diff_us(echo_start, echo_end);
        echo_done = true;
    }
}
void init_echo_callback(const uint GPIO_IN) {
    gpio_set_irq_enabled_with_callback(GPIO_IN,GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL,true,&echo_irq_callback);
}
void send_trigger_pulse(const uint GPIO_OUT,double* distance) {
    gpio_put(GPIO_OUT,1);
    sleep_us(10);
    gpio_put(GPIO_OUT,0);

    if (echo_done) {
        *distance = (echo_duration_us * 0.0343) / 2;
        echo_done = false;
    }
}



