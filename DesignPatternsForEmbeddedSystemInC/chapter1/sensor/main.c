#include "sensor.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    Sensor *p_Sensor0 = NULL, *p_Sensor1 = NULL;
    p_Sensor0 = sensor_create();
    p_Sensor1 = sensor_create();

    p_Sensor0->value = 99;
    p_Sensor1->value = -2;

    printf("#info: %s = %d\r\n", "sensor_get_value(p_Sensor0)",\
            sensor_get_value(p_Sensor0));
    printf("#info: %s = %d\r\n", "sensor_get_value(p_Sensor1)",\
            sensor_get_value(p_Sensor1));

    sensor_destory(p_Sensor0);
    sensor_destory(p_Sensor1);
    return 0;
}
