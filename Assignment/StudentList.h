#pragma once

#include "List.h"
#include <stdint.h>
#include "Student.h"

typedef struct StudentList *studentList_t;
studentList_t studentList_create();
list_listReturnCode studentList_addStudent(studentList_t self, student_t *student);
student_t *studentList_getStudent(studentList_t self, uint16_t index);
list_listReturnCode studentList_removeStudent(studentList_t self, student_t *student);
uint16_t studentList_noOfStudents(studentList_t self);
