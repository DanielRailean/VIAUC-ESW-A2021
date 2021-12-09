//
// Created by dd on 08/12/2020.
//

#ifndef ROOM_H
#define ROOM_H

#include "Temperature.h"
#include "Humidity.h"
#include <stdint.h>

typedef enum {
    ROOM_PERFECT,
    ROOM_GOOD,
    ROOM_AVERAGE,
    ROOM_BAD,
    ROOM_DISASTER,
    ROOM_NOT_AVAILABLE
}room_roomHealth_t;

typedef struct Room* room_t;
room_t room_create(char* location, uint16_t sqMeter);
void room_destroy(room_t self);
void room_addTemperature(room_t self,temperature_t temp);
void room_addHumidity(room_t self, humidity_t hum);
room_roomHealth_t room_getRoomHealth(room_t self);
char* room_getRoomHealthText(room_roomHealth_t health);
char* room_getLocation(room_t self);
uint16_t room_getArea(room_t self);

#endif
