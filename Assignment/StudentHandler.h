//
// Created by dd on 21/11/2021.
//

#ifndef ASSIGNMENT_STUDENTHANDLER_H
#define ASSIGNMENT_STUDENTHANDLER_H

#pragma  once

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Student.h"


void printAllStudentsInfo(List* students);
Student* searchStudentById(List* studentList, int id);
Student* searchStudentByLastName(List* studentList, char* lastName);

#endif //ASSIGNMENT_STUDENTHANDLER_H
