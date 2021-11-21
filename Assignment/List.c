//
// Created by dd on 21/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct data {
    int id;
};

typedef struct data data_t;

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
    data_t * searched = item;
    data_t * current = temp->data;

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
    List* toFree = *list;
    *list = 0;
    int size = noOfItems(toFree);
    while(size>0){
        int i = size -1;
        void* item = getItem(toFree,i);
        removeItem(&toFree,item);
        size = noOfItems(*list);
    }
    return OK;
};

List* createNode(void* data){
    List* result = (List *)calloc(1,sizeof(List));
    result->data = data;
    result->next = 0;
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


