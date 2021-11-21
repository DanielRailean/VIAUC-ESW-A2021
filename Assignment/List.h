//
// Created by dd on 21/11/2021.
//
#ifndef ASSIGNMENT_LIST_H
#define ASSIGNMENT_LIST_H

#pragma once
#include "stdint.h"

enum ListReturnCode{
    OK,
    EMPTY,
    NOT_FOUND,
    null,
    ERROR
};

void* create();
enum ListReturnCode destroy();
enum ListReturnCode addItem(void* item);
enum ListReturnCode getItemObj(void** item, uint16_t index);
enum ListReturnCode removeItem(void* item);
uint16_t noOfItems();
void* getItem(uint16_t index);

#endif //ASSIGNMENT_LIST_H
