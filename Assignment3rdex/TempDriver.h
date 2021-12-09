//
// Created by dd on 08/12/2020.
//


#ifndef TEMPDRIVER_H
#define TEMPDRIVER_H

#include <stdint.h>

void temperatureDriver_initDriver(uint8_t port);
float temperatureDriver_getVoltage();

#endif
