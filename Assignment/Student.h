#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef struct Student *student_t;
student_t *student_create(char *firstName, char *lastName, uint16_t studentId, char *nationality);
void student_printInfo(student_t self);
uint16_t student_getId(student_t self);
char *student_getLastName(student_t self);