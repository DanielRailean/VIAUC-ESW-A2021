//
// Created by dd on 08/12/2020.
//

#include "Temperature.h"
#include <stdbool.h>
#include <corecrt_malloc.h>
#include "TempDriver.h"

typedef struct Temperature {
    float latestTemp;
    uint8_t driverPort;
}Temperature;

static float calculateTemp(float voltage) {
    return 15.0+(voltage * 5.0);
}

temperature_t* temperature_create(uint8_t portNo) {
    temperature_t created = calloc(sizeof(Temperature), 1);
    if (NULL == created) {
        return NULL;
    }
    created->latestTemp = 0.0;
    created->driverPort = portNo;
    temperatureDriver_initDriver(portNo);
    return created;
}

void temperature_destroy(temperature_t self){
    free(self);
}

void temperature_measure(temperature_t self) {
    self->latestTemp = calculateTemp(temperatureDriver_getVoltage());
}

float temperature_getTemperature(temperature_t self){
    float temp = self->latestTemp;
    return temp;
}