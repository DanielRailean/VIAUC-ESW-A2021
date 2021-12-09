#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <Windows.h>
#include "HealthHandler.h"

static healthHandler_t* healthHandler;
static room_t* living;
static room_t* bath;

void delayMs(int ms){
    printf("delay: %d",ms);
}

void setupApplication(){
    healthHandler = healthHandler_create();

    living = room_create("Living", 11);
    bath = room_create("Bath", 12);

    temperature_t* t0 = temperature_create(0);
    temperature_t* t1 = temperature_create(1);
    temperature_t* t2 = temperature_create(2);
    humidity_t* h1 = humidity_create(3);
    humidity_t* h2 = humidity_create(4);

    room_addTemperature(living, t0);
    room_addTemperature(living, t1);
    room_addHumidity(living, h1);

    room_addTemperature(bath, t2);
    room_addHumidity(bath, h2);
}

void runApplication(){
    healthHandler_addRoom(healthHandler, bath);
    healthHandler_addRoom(healthHandler, living);

    healthHandler_showBuildingHealth(healthHandler);
}



int main() {
    setupApplication();
    runApplication();
    delayMs(1337);
    return 0;
}




