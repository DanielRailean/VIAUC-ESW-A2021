//
// Created by dd on 21/11/2021.
//

#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Student* createStudent(char* firstName,char* lastName, int studentId,char* nationality){
    Student * result = (Student *)calloc(1,sizeof(Student));
    result->firstName = malloc(sizeof (firstName)) ;
    strcpy(result->firstName,firstName);
    result->lastName = malloc(sizeof (lastName)) ;
    strcpy(result->lastName,lastName);
    result->nationality = malloc(sizeof (nationality)) ;
    strcpy(result->nationality,nationality);
    result->studentId = studentId;
    return result;

};
void printInfo(void* student){
    Student * printed = student;

    printf("{\nStudentId: %d\nFirstName: %s\nLastName: %s\nNationality: %s\n}\n", printed->studentId,printed->firstName,printed->lastName,printed->nationality);
};
