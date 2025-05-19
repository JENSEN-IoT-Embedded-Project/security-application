#include "jsonify.h"
#include <stdio.h>

char* create_json(char* user_id, double distance){
        static char json_data[256];

        snprintf(json_data, sizeof(json_data),
                "{\"device-id\": \"%s\", \"distance\": %lf}",
                user_id, distance);
        return json_data;
}
