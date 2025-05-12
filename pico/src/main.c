#include "hcsr04.h"
#include "alarmcount.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include <stdio.h>
#include "buzzer_melodies.h"
#include <lwip/ip_addr.h>
#include "lwip/apps/mqtt.h"

#include "mqtt_functions.h"
#include "mqtt_config.h"

#define TRIGG 15 
#define ECHO 14


#define WIFI_SSID "add yours"
#define WIFI_PASS "add yours"
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
    bool alarm_is_active = false;
    //initiate callback function that will run when ECHO pin is either rising or falling.
    init_echo_callback(ECHO);
    uint buzzer = 11;
    gpio_pwm_setup(buzzer);
     mqtt_client_t *client = NULL;
    struct mqtt_connect_client_info_t pico;
    if (!mqtt_connect(&client, _MQTT_BROKER_IP, MQTT_DEVICE_NAME, &pico)) {
        printf("MQTT connect failed\n");
    }

    // Wait until MQTT is connected (timeout after 10 seconds)
    int waited = 0;
    while (!mqtt_connected && waited < 10000) {
        cyw43_arch_poll();
        sleep_ms(10);
        waited += 10;
    }


    	
    while(1){
        //send trigger pulse and generate distance to object  to the second parameter in the function.
        for(int i = 0; i < 3 ; i++){ 
            send_trigger_pulse(TRIGG,&distance);
            sleep_ms(100);
        }
        send_trigger_pulse(TRIGG,&distance);
        printf("distance: %.2f\n",distance);
        sleep_ms(100);

        if (distance <= 5){
        	alarm_is_active = true;
        }
        if (alarm_is_active){
        	alarmtriggered(&alarm_is_active, buzzer);
            sleep_ms(1000);
            if (mqtt_connected) {
                const char *topic = "motion/sensor";
                const char *msg = "motion_detected";
                err_t pub_result = mqtt_publish(client, topic, msg, strlen(msg), 0, 0, NULL, NULL);

                if (pub_result == ERR_OK) {
                    printf("MQTT publish OK\n");
                } else {
                    printf("MQTT publish failed: %d\n", pub_result);
                }
            }

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
