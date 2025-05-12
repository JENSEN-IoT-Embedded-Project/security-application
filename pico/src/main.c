#include "hcsr04.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include <stdio.h>

#define TRIGG 15 
#define ECHO 14


#define WIFI_SSID ""
#define WIFI_PASS ""
void connect_to_wifi();

int main() 
{   
    //init pins for ultrasonicsensor
    stdio_init_all();
    sleep_ms(1000);
    gpio_init(TRIGG);
    gpio_set_dir(TRIGG,1);
    gpio_init(ECHO);
    gpio_set_dir(ECHO,0);
    connect_to_wifi();
    double distance = 0;
    //initiate callback function that will run when ECHO pin is either rising or falling.
    init_echo_callback(ECHO);
	bool alarm_is_active = false;
	
    while(1){
        //send trigger pulse and generate distance to object  to the second parameter in the function.
        send_trigger_pulse(TRIGG,&distance);
        printf("distance: %.2f\n",distance);
        sleep_ms(1000);
        if (distance <= 5){
        	alarm_is_active = true;
        }
        if (alarm_is_active){
        	alarmtriggered();
        }
    }
    return 0;
}

void connect_to_wifi(){
//enabling dependencies
	cyw43_arch_init();
	cyw43_arch_enable_sta_mode();

	printf("Attempting to connect to wifi ...");
	
	while (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASS, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
		printf("Failed to connect ..-");
		sleep_ms(3000);
	}
	
	printf("Connected to wifi: %s\n", WIFI_SSID);
	
}
