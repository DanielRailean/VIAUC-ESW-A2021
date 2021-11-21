//
// Created by dd on 21/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Student.h"

#ifndef ASSIGNMENT_STUDENTLIST_H
#define ASSIGNMENT_STUDENTLIST_H

#pragma once

enum ListReturnCode addStudent(List* list,Student* student);
enum ListReturnCode removeStudent(List** list,Student* student);
uint16_t noOfStudents(List* list);
enum ListReturnCode getStudent(List* list,Student** student, uint16_t index);


#endif //ASSIGNMENT_STUDENTLIST_H
