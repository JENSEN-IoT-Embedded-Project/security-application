#include "wifi.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include <stdio.h>

void connect_to_wifi(){
//enabling dependencies
	cyw43_arch_init();
	cyw43_arch_enable_sta_mode();

	printf("Attempting to connect to wifi ...");
	
	if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASS, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
		printf("Failed to connect ..-");
	}
	else {
		printf("Connected to wifi: %s\n", WIFI_SSID);
	}
}
