#include <stdio.h>
#include "pico/stdlib.h"


bool alarmtriggered() {
    const int alarmcounter = 10;

    if (!alarm_is_active) {
        printf("alarm not triggered\n");
        return false;
    }

    for (int i = 0; i < alarmcounter; i++) {
        sleep_ms(1000);
        // if (gpio_get(CANCEL_PIN)) {
        //     printf("alarm cancelled\n");
        //     return false;	
        // }
    }

    printf("alarm triggered!\n");
    alarm_is_active = false;
    return false;
}

void save_data(){
	if (!alarm_is_active){
		printf("nothing to save");
	}
	printf("saved all data"); // save data etc 
}
