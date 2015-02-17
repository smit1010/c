#include "sensor.h"
#include <stdio.h>

void sensor_init(Sensor *const me){

}

void sensor_cleanup(Sensor *const me){

}

int sensor_get_filter_frequency(const Sensor *const me) {
    return me->filterFrequency;
}

void sensor_set_filter_frequency(Sensor *const me, int p_filterFrequency) {
    me->filterFrequency = p_filterFrequency;
}

int sensor_get_update_frequency(const Sensor *const me) {
    return me->updateFrequency;
}

void sensor_set_upate_frequency(Sensor *const me, int p_updateFrequency) {
    me->updateFrequency = p_updateFrequency;
}

int sensor_get_value(const Sensor * const me) {
    return me->value;
}

Sensor *sensor_create(void){
    Sensor *me = (Sensor*) malloc(sizeof(Sensor));
    if (NULL == me)
    {
        printf("ERR: malloc ERR\r\n");
        return NULL;
    }

    sensor_init(me);
    return me;
}

void sensor_destory(Sensor *const me) {
    if (NULL == me)
        return NULL;

    sensor_cleanup(me);
    free(me);
}
 
