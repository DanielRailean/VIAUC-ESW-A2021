//
// Created by dd on 21/11/2021.
//
#ifndef ASSIGNMENT_LIST_H
#define ASSIGNMENT_LIST_H

#pragma once
#include "stdint.h"


struct node {
    void* data;
    struct node* next;
};

typedef struct node List;

enum ListReturnCode{
    OK,
    EMPTY,
    NOT_FOUND,
    null,
    ERROR
};

List* create();
enum ListReturnCode destroy(List** list);
enum ListReturnCode addItem(List* list,void* item);
//enum ListReturnCode getItemObj(void** item,List* list, uint16_t index);
enum ListReturnCode removeItem(List** list,void* item);
uint16_t noOfItems(List* list);
void* getItem(List* list,uint16_t index);
void printList(List* list, void (*fptr)(void *));

#endif //ASSIGNMENT_LIST_H
