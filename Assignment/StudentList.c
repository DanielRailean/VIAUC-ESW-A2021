#include "StudentList.h"
#include <stdlib.h>

typedef struct StudentList
{
    list_t *list;
} StudentList;

studentList_t studentList_create(list_t list)
{
    studentList_t created = calloc(sizeof(StudentList), 1);
    if (NULL == created)
    {
        return NULL;
    }
    created->list = list;
    return created;
}

list_listReturnCode studentList_addStudent(studentList_t self, student_t *student)
{
    uint16_t added = list_addItem(self->list, student);
    if (added == 0)
    {
        free(added);
        return OK;
    }
    else
    {
        free(added);
        return ERROR;
    }
}

student_t *studentList_getStudent(studentList_t self, uint16_t index)
{
    student_t *student;
    uint16_t returned = list_getItem(self->list, &student, index);
    if (returned == 0)
    {
        free(returned);
        return student;
    }
    else
    {
        free(returned);
        return NULL;
    }
}

list_listReturnCode studentList_removeStudent(studentList_t self, student_t *student)
{
    uint16_t removed = list_removeItem(self->list, student);
    if (removed == 0)
    {
        free(removed);
        return OK;
    }
    else
    {
        free(removed);
        return ERROR;
    }
}

uint16_t studentList_noOfStudents(studentList_t self)
{
    return list_noOfItems(self->list);
}