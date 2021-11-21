//
// Created by dd on 21/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct node {
    void* value;
    struct node* next;
};

struct student {
    int id;
    char* name;
};

typedef struct node node_t;
typedef struct student student_t;

void* create(){

};
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
    return temp->value;
};

void printList(node_t* head){
    node_t* temp = head;

    while(temp!=NULL){
        printf("-%.2f",*(float *)temp->value);
        temp = temp->next;
    }
    printf("\n");
}

node_t* createNode(void* value,size_t data_size){
    node_t* result = (node_t *)calloc(1,sizeof(node_t));
//    result->value = malloc(data_size);
    result->value = value;
//    for(int i=0; i <data_size; i++){
//        *(char *)(result->value + i) = *(char *)(value + i);
//    }
    result->next = NULL;
    return result;
};

node_t* insertAtHead(node_t** head, void* value){
    unsigned int_size = sizeof(float);
    node_t* temp = createNode(value,int_size);
    temp->next = *head;
    *head = temp;
    return temp;
};
enum ListReturnCode insertAtEnd(node_t* head, void* value){
    unsigned int_size = sizeof(float);
    node_t* added = createNode(value,int_size);
    node_t* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = added;
    return OK;
};


int main(){
    node_t *head = NULL;



    float add = 10.1f;

    insertAtHead(&head,&add);
    insertAtHead(&head,&add);
    insertAtHead(&head,&add);

    insertAtEnd(head,&add);
    insertAtEnd(head,&add);
    insertAtEnd(head,&add);

    float at2 =  *(float *)getItemIndex(head, 2);

    printList(head);

    printf("%d\n", noOfItems(head));
    printf("%f\n", at2);
    return 0;
}

