//
// Created by dd on 08/12/2020.
//


#include "List.h"
#include <stdlib.h>

typedef struct Node {
    void* value;
    struct Node* next;
}Node;

typedef struct List {
    Node* head;
} List;

Node* list_findTail(Node* head) {
    if (!head->next) {
        return head;
    }else{
        return list_findTail(head->next);
    }
}

uint16_t list_countToTail(Node* head) {
    if (head->next == NULL) {
        return 1;
    }else{
        return list_countToTail(head->next)+1;
    }
}

Node* list_findNodeByIndex(Node* head, uint16_t index) {
    if (index != 0 && head->next) {
        return list_findNodeByIndex(head->next,index - 1);
    } else if(head){
        return head;
    }else{
        return NULL;
    }
}

Node* list_findNodeByItem(Node* head, void** item) {
    if (head->value == *item) { 
        return head;
    } else if(head->value == item){
        return head;
    }else if (!head->next) {
        return NULL;
    }else {
        return list_findNodeByItem(head->next, item);
    }
}

Node* list_findParentNodeOfNode(Node* head, Node* childNode) {
    if (head->next == childNode) {
        return head;
    }else if (!head->next) {
        return NULL;
    }else{
        return list_findParentNodeOfNode(head->next, childNode);
    }
}

ListReturnCode list_deleteNodesCascade(Node* head){
    if(!head){
        return OK;
    } else{
        if(head->next){
            Node* next = head->next;
            free(head);
            return list_deleteNodesCascade(next);
        } else{
            free(head);
            return OK;
        }
    }
}

list_t list_create() {
    list_t new_list = calloc(sizeof(List), 1);
    if (NULL == new_list) {
        return NULL;
    }
    return new_list;
}

ListReturnCode list_destroy(list_t self) {
    if (NULL != self) {
        if(list_deleteNodesCascade(self->head) == 0){
            free(self);
            return OK;
        }else{
            free(self);
            return OK;
        }
    } else {
        return NULLL;
    }
}

ListReturnCode list_addItem(list_t self, void** item) {
    if(NULL != self){
        Node* new_node = calloc(sizeof(Node), 1);
        if (NULL == new_node) {
            return ERROR;
        }
        new_node->value = item;
        if(!self->head){
            self->head = new_node;
        } else{
            Node* tail = list_findTail(self->head);
            tail->next = new_node;
        }
        return OK;
    } else{
        return NULLL;
    }

}

ListReturnCode list_getItem(list_t self, void** item, uint16_t index) {
    if(NULL != self){
        Node* item_node = list_findNodeByIndex(self->head, index);
        if(!item_node){
            return NOT_FOUND;
        }
        *item = item_node->value;
        return OK;
    } else{
        return NULLL;
    }
}

ListReturnCode list_removeItem(list_t self, void** item) {
    if(NULL != self){
        Node* node_to_delete = list_findNodeByItem(self->head, item);
        if(!node_to_delete){
            return NOT_FOUND;
        }
        Node* nextTemp = node_to_delete->next;
        if(self->head == node_to_delete){
            self->head = nextTemp;
        } else{
            Node* parentNode = list_findParentNodeOfNode(self->head, node_to_delete);
            parentNode->next = nextTemp;
        }
        free(node_to_delete);
        return OK;
    } else{
        return NULLL;
    }
}

uint16_t list_noOfItems(list_t self) {
    if(!self->head){
        return 0;
    } else{
        return list_countToTail(self->head);
    }
}