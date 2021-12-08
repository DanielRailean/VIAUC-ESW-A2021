#include <stdlib.h>
#include "List.h"

typedef struct Node
{
    void *value;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
} List;

static Node *list_findTail(Node *head)
{
    if (!head->next)
    {
        return head;
    }
    else
    {
        return list_findTail(head->next);
    }
}

static uint16_t list_countToTail(Node *head)
{
    if (head->next == NULL)
    {
        return 1;
    }
    else
    {
        return list_countToTail(head->next) + 1;
    }
}

static Node *list_findNodeByIndex(Node *head, uint16_t index)
{
    if (index != 0 && head->next)
    {
        return list_findNodeByIndex(head->next, index - 1);
    }
    else if (head)
    {
        return head;
    }
    else
    {
        return NULL;
    }
}

static Node *list_findNodeByItem(Node *head, void **item)
{
    if (head->value == *item)
    {
        return head;
    }
    else if (head->value == item)
    {
        return head;
    }
    else if (!head->next)
    {
        return NULL;
    }
    else
    {
        return list_findNodeByItem(head->next, item);
    }
}

static Node *list_findParentNodeOfNode(Node *head, Node *childNode)
{
    if (head->next == childNode)
    {
        return head;
    }
    else if (!head->next)
    {
        return NULL;
    }
    else
    {
        return list_findParentNodeOfNode(head->next, childNode);
    }
}

static list_listReturnCode list_deleteNodesCascade(Node *head)
{
    if (!head)
    {
        return OK;
    }
    else
    {
        if (head->next)
        {
            Node *next = head->next;
            free(head->value);
            free(head);
            return list_deleteNodesCascade(next);
        }
        else
        {
            free(head->value);
            free(head);
            return OK;
        }
    }
}

list_t list_create()
{
    list_t new_list = calloc(sizeof(List), 1);
    if (NULL == new_list)
    {
        return NULL;
    }
    return new_list;
}

list_listReturnCode list_destroy(list_t self)
{
    if (NULL != self)
    {
        if (list_deleteNodesCascade(self->head) == 0)
        {
            free(self);
            return OK;
        }
        else
        {
            free(self);
            return OK;
        }
    }
    else
    {
        return NULLL;
    }
}

list_listReturnCode list_addItem(list_t self, void *item)
{
    if (NULL != self)
    {
        Node *added = calloc(sizeof(Node), 1);
        if (NULL == added)
        {
            return ERROR;
        }
        added->value = item;
        if (!self->head)
        {
            self->head = added;
        }
        else
        {
            Node *tail = list_findTail(self->head);
            tail->next = added;
        }
        return OK;
    }
    else
    {
        return NULLL;
    }
}

list_listReturnCode list_getItem(list_t self, void **item, uint16_t index)
{
    if (NULL != self)
    {
        Node *returned = list_findNodeByIndex(self->head, index);
        if (!returned)
        {
            return NOT_FOUND;
        }
        *item = returned->value;
        return OK;
    }
    else
    {
        return NULLL;
    }
}

list_listReturnCode list_removeItem(list_t self, void *item)
{
    if (NULL != self)
    {
        Node *deleted = list_findNodeByItem(self->head, item);
        if (!deleted)
        {
            return NOT_FOUND;
        }
        Node *nextTemp = deleted->next;
        if (self->head == deleted)
        {
            self->head = nextTemp;
        }
        else
        {
            Node *parentNode = list_findParentNodeOfNode(self->head, deleted);
            parentNode->next = nextTemp;
        }
        free(deleted);
        return OK;
    }
    else
    {
        return NULLL;
    }
}

uint16_t list_noOfItems(list_t self)
{
    if (!self->head)
    {
        return 0;
    }
    else
    {
        return list_countToTail(self->head);
    }
}