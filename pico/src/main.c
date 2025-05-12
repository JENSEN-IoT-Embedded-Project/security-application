#include "hcsr04.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include "wifi.h"

#define TRIGG 15 
#define ECHO 14 


int main() 
{   
    //init pins for ultrasonicsensor
    stdio_init_all();
    sleep_ms(1000);
    gpio_init(TRIGG);
    gpio_set_dir(TRIGG,1);
    gpio_init(ECHO);
    gpio_set_dir(ECHO,0);
    stdio_init_all();

    connect_to_wifi();
    double distance = 0;
    //initiate callback function that will run when ECHO pin is either rising or falling.
    init_echo_callback(ECHO);


    while(1){
        //send trigger pulse and generate distance to object  to the second parameter in the function.
        send_trigger_pulse(TRIGG,&distance);
        printf("distance: %.2f\n",distance);
        sleep_ms(1000);
    }
    return 0;
}
