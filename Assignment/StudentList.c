//
// Created by dd on 21/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Student.h"
#include "StudentList.h"


enum ListReturnCode addStudent(List* list,Student* student){
    int index = noOfStudents(list);
    student->id = index+1;
    addItem(list,student);
};
enum ListReturnCode removeStudent(List** list,Student* student){
    removeItem(list,student);
    return OK;
};
uint16_t noOfStudents(List* list){
    return noOfItems(list);
};
enum ListReturnCode getStudent(List* list,Student ** student, uint16_t index){
    *student = getItem(list,index);
    return OK;
};
