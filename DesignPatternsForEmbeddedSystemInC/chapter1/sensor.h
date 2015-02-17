#ifndef sensor_h
#define sensor_h

#define MEMORYMAPPED 1
#define PORTMAPPED 2
#define WRITEADDR 0
#define READADDR 1
#define INP(f)

typedef struct Sensor Sensor;
struct Sensor {
    int filterFrequency;
    int updateFrequency;
    int value;
};

int sensor_get_filter_frequency(const Sensor *const me);
void sensor_set_filter_frequency(Sensor *const me, int p_filterFrequency);
int sensor_get_update_frequency(const Sensor *const me);
void sensor_set_upate_frequency(Sensor *const me , int p_updateFrequency);
Sensor* sensor_create(void);
void sensor_destory(Sensor *const me);
#endif /*sensor_h*/
