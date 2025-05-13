#include "jsonify.h"
#include <stdio.h>

char* create_json(char* user_id, char* date, char* time,double distance){
        static char json_data[256];

        snprintf(json_data, sizeof(json_data),
                "{\"user_id\": \"%s\", \"date\": \"%s\", \"time\": \"%s\", \"distance\": \"%lf\"}",
                user_id, date, time);
        return json_data;
}
