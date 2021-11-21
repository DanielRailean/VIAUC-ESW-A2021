#include <stdio.h>
#include "StudentHandler.h"
#include "StudentList.h"


int main(){
    List *list = create();

    addStudent(list, createStudent("Dan","Rai",20,"MDL"));
    addStudent(list, createStudent("Mar","Vic",20,"BG"));
    addStudent(list, createStudent("Cos","Tri",20,"RO"));
    addStudent(list, createStudent("Mak","Viz",20,"HU"));

    printf("Size after insert: %d\n", noOfItems(list));


    Student * nr2;
    getStudent(list,&nr2,2);

    printInfo(nr2);
    printAllStudentsInfo(list);

    removeStudent(&list,nr2);
    printf("Size after delete 1: %d\n", noOfItems(list));

    destroy(&list);

    printf("Size after destroy: %d\n", noOfItems(list));

    printAllStudentsInfo(list);

    return 0;
}
