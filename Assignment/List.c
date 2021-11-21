//
// Created by dd on 21/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct node {
    void* data;
    struct node* next;
};

struct student {
    int id;
    float weight;
};

typedef struct node node_t;
typedef struct student student_t;

enum ListReturnCode destroy(){

};
enum ListReturnCode addItem(void* item){
//    void* temp = malloc(sizeof (item));


};
enum ListReturnCode getItemObj(void** item, uint16_t index){

};
enum ListReturnCode removeItem(void* item){

};
uint16_t noOfItems(node_t* head){
    int size = 1;
    node_t* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
        size++;
    }
    return size;

};
void* getItemIndex(node_t* head,uint16_t index){
    int current = 0;
    node_t* temp = head;

    while(current<index){
        current++;
        temp = temp->next;
    }
    return temp->data;
};

void printList(node_t* head, void (*fptr)(void *)){
    node_t* temp = head;

    while(temp!=NULL){
        (*fptr)(temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printStudent(void* student)
{
    student_t * printed = student;
    printf("\n{\nStudent Id: %d\nWeight: %.1f\n}", printed->id,printed->weight);
}
node_t* createNode(void* data){
    node_t* result = (node_t *)calloc(1,sizeof(node_t));
    result->data = data;
    result->next = NULL;
    return result;
};

student_t * createStudent(int id, float weight){
    student_t * result = (node_t *)calloc(1,sizeof(student_t));
    result->id = id;
    result->weight = weight;
    return result;
};

node_t* insertAtHead(node_t** head, void* data){
    node_t* temp = createNode(data);
    temp->next = *head;
    *head = temp;
    return temp;
};
enum ListReturnCode insertAtEnd(node_t* head, void* data){
    node_t* added = createNode(data);
    node_t* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = added;
    return OK;
};


int main(){
    node_t *head = NULL;



    student_t* add = createStudent(199,20);

    insertAtHead(&head,createStudent(1,21));
    insertAtHead(&head,createStudent(2,31));
    insertAtHead(&head,createStudent(3,51));

    insertAtEnd(head,add);
    insertAtEnd(head,add);
    insertAtEnd(head,add);

    student_t* at2 =  getItemIndex(head, 2);

    printList(head,printStudent);
//
//    printf("%d\n", noOfItems(head));

    printf("at index 2: %d\n", at2->id);
    return 0;
}

