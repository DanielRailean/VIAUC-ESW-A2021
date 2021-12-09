//
// Created by dd on 08/12/2020.
//

#include "HumidityDriver.h"
#include <time.h>
#include <stdlib.h>

void humidityDriver_initDriver() {
    srand(time(NULL));
}

uint8_t humidityDriver_getHumidity() {
    return (rand() % (85 - 35 + 1)) + 35;
}