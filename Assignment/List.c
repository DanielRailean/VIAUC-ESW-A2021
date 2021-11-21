//
// Created by dd on 21/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "List.h"


struct student {
    int id;
    float weight;
};

typedef struct student student_t;


//enum ListReturnCode getItemObj(void** item,List* list, uint16_t index){
//
//};

List* create(){
    List* result = (List *)calloc(1,sizeof(List));
    result->data = 0;
    result->next = 0;
    return result;
};

enum ListReturnCode removeItem(List** list,void* item){
    if(list==0){
        return EMPTY;
    }
    if(item==0){
        return ERROR;
    }
    int deleted = 0;
    List* temp = *list;
    student_t * searched = item;
    student_t * current = temp->data;

    if(temp->next==0){
        free(*list);
        free(item);
        temp->next=0;
        *list = 0;
        return OK;
    }
    while(searched->id==current->id){
        List* old = *list;
        *list = temp->next;
        temp=*list;
        current = temp->data;
        deleted++;
        free(old);
    }
    while(temp->next!= 0){
        current = temp->next->data;
        if(current->id==searched->id){
            List * toBeDeleted = temp->next;
            temp->next = temp->next->next;
            free(toBeDeleted);
            deleted++;
        }else{
            temp = temp->next;
        }
    }
    if(deleted>0) return OK;
    else return NOT_FOUND;
};
uint16_t noOfItems(List* list){
    if(list ==0){
        return 0;
    }
    int size = 1;
    List* temp = list;

    while(temp->next!=0){
        temp = temp->next;
        size++;
    }
    return size;

};
void* getItem(List* list,uint16_t index){
    int current = 0;
    List* temp = list;

    while(current<index){
        current++;
        temp = temp->next;
    }
    return temp->data;
};

void printList(List* list, void (*fptr)(void *)){
    List* temp = list;
    if(list==0){
        printf("List empty");
        return;
    }

    while(temp!=0){
        (*fptr)(temp->data);
        temp = temp->next;
    }
    printf("\n");
}


enum ListReturnCode destroy(List** list){
    int size = noOfItems(*list);
    while(size>0){
        int i = size -1;
        void* item = getItem(*list,i);
        removeItem(list,item);
        size = noOfItems(*list);
    }
    return OK;
};
void printStudent(void* student)
{
    student_t * printed = student;
    printf("{\nStudent Id: %d\nWeight: %.1f\n}\n", printed->id,printed->weight);
}
List* createNode(void* data){
    List* result = (List *)calloc(1,sizeof(List));
    result->data = data;
    result->next = 0;
    return result;
};

student_t * createStudent(int id, float weight){
    student_t * result = (student_t *)calloc(1,sizeof(student_t));
    result->id = id;
    result->weight = weight;
    return result;
};

List* insertAtStart(List** list, void* data){
    List* temp = createNode(data);
    temp->next = *list;
    *list = temp;
    return temp;
};
enum ListReturnCode addItem(List* list, void* data){
    List* added = createNode(data);
    List* temp = list;

    if(list->data==0){
        list->data = data;
    }else{
        while(temp->next!=0){
            temp = temp->next;
        }
        temp->next = added;
        return OK;
    }
};


int main(){
    List *list = create();

    addItem(list,createStudent(1,21));
    addItem(list,createStudent(2,31));
    addItem(list,createStudent(3,51));

    addItem(list,createStudent(4,71));
    addItem(list, createStudent(5,1));
    addItem(list, createStudent(6,12));

    printList(list,printStudent);


    printf("Size after insert: %d\n", noOfItems(list));

    printf("Deleted: %d\n",removeItem(&list, createStudent(6,1)));

    printf("Size after delete 1: %d\n", noOfItems(list));
    printf("Deleted: %d\n",removeItem(&list, createStudent(1,1)));


    printf("Size after delete 2: %d\n", noOfItems(list));

    destroy(&list);

    printf("Size after destroy: %d\n", noOfItems(list));

    printList(list,printStudent);

    return 0;
}

