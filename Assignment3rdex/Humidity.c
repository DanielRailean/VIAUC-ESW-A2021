//
// Created by dd on 08/12/2020.
//

#include "Humidity.h"
#include <stdint.h>
#include <corecrt_malloc.h>
#include "HumidityDriver.h"
typedef struct Humidity{
    uint8_t latestHumidity;
    uint8_t driverPort;
}Humidity;

humidity_t humidity_create(uint8_t portNo) {
    humidity_t created = calloc(sizeof(Humidity), 1);
    if (NULL == created) {
        return NULL;
    }
    created->latestHumidity = 0;
    created->driverPort = portNo;
    humidityDriver_initDriver(portNo);
    return created;
}

void humidity_destroy(humidity_t self){
    free(self);
}

void humidity_measure(humidity_t self) {
    self->latestHumidity = humidityDriver_getHumidity();
}

float humidity_getHumidity(humidity_t self) {
    return self->latestHumidity;
}

