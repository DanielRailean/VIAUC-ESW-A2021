#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Student
{
    char firstName[25];
    char lastName[25];
    uint16_t studentId;
    char nationality[25];
} Student;

student_t *student_create(char *firstName, char *lastName, uint16_t studentId, char *nationality)
{
    Student *created = calloc(sizeof(Student), 1);
    if (NULL == created)
    {
        return 3;
    }
    strncpy(created->firstName, firstName, sizeof(created->firstName) - 1);
    strncpy(created->lastName, lastName, sizeof(created->firstName) - 1);
    created->studentId = studentId;
    strncpy(created->nationality, nationality, sizeof(created->firstName) - 1);
    return created;
}

void student_printInfo(student_t self)
{
    printf("%s, %s, %d, %s\n", self->firstName, self->lastName, self->studentId, self->nationality);
}

uint16_t student_getId(student_t self)
{
    return self->studentId;
}

char *student_getLastName(student_t self)
{
    return self->lastName;
}
char *student_getFirstName(student_t self)
{
    return self->firstName;
}