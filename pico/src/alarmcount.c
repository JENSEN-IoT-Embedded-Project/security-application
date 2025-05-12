#include <stdio.h>
#include "pico/stdlib.h"
#include "alarmcount.h"
#include "buzzer_melodies.h"
void alarmtriggered(bool* alarm_is_active, uint buzzer) {
    const int alarmcounter = 10;
    uint btn = 16;
    gpio_init(btn);
    gpio_set_dir(btn,0);
    gpio_pull_up(btn);
    
    *alarm_is_active = false;


    for (int i = 0; i < alarmcounter; i++) {
        sleep_ms(1000);
        // if (gpio_get(CANCEL_PIN)) {
        //     printf("alarm cancelled\n");
        //     return false;	
        // if(gpio_get(btn)) {
        if(!gpio_get(btn)) return;
        
        printf("%d\n",i);
    }
    melody_careless_whisper(buzzer);
    printf("alarm triggered!\n");
}


