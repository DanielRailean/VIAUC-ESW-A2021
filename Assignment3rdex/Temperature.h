//
// Created by dd on 08/12/2020.
//

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdint.h>

typedef struct Temperature* temperature_t;

temperature_t* temperature_create(uint8_t portNo);
void temperature_destroy(temperature_t self);
void temperature_measure(temperature_t self);
float temperature_getTemperature(temperature_t self);

#endif
