#include "List.h"
#include "Student.h"
#include "StudentList.h"
#include "StudentHandler.h"

int main()
{
    student_t student1;
    student1 = student_create("Dan", "R", 124, "MDL");
    student_t student2;
    student2 = student_create("Const", "Trip", 123, "ROM");
    student_t student3;
    student3 = student_create("Mar", "Kas", 223, "BG");

    list_t list;
    list = list_create();

    studentList_t studentList;
    studentList = studentList_create(list);

    studentHandler_t studentHandler;
    studentHandler = studentHandler_create(studentList);

    studentHandler_addStudent(studentHandler, student1);
    studentHandler_addStudent(studentHandler, student2);
    studentHandler_addStudent(studentHandler, student3);


    student_t *returned = studentHandler_searchStudentByLastName(studentHandler, "Trip");
    student_t *returned1 = studentHandler_searchStudentById(studentHandler, 124);
    student_t *returned2 = studentHandler_searchStudentById(studentHandler, 223);

    studentHandler_printStudentInfo(studentHandler,returned);
    studentHandler_printStudentInfo(studentHandler,returned1);
    studentHandler_printStudentInfo(studentHandler,returned2);

    studentHandler_printAllStudentsInfo(studentHandler);

    return 0;
}
