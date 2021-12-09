//
// Created by dd on 08/12/2020.
//


#ifndef HUMIDITY_H
#define HUMIDITY_H

#include <stdint.h>

typedef struct Humidity* humidity_t;
humidity_t humidity_create(uint8_t portNo);
void humidity_destroy(humidity_t self);
void humidity_measure(humidity_t self);
float humidity_getHumidity(humidity_t self);

#endif
