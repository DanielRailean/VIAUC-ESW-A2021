//
// Created by dd on 21/11/2021.
//

#ifndef ASSIGNMENT_STUDENT_H
#define ASSIGNMENT_STUDENT_H
#pragma  once

struct student {
    int id;
    char* firstName;
    char* lastName;
    char* nationality;
    int studentId;
};

typedef struct student Student;

Student* createStudent(char* firstName,char* lastName, int studentId,char* nationality);
void printInfo(void* student);
#endif //ASSIGNMENT_STUDENT_H
