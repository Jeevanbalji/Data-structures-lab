#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

typedef struct
{
    struct Node *head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate()
{
    MyLinkedList *list = (MyLinkedList*)malloc(sizeof(MyLinkedList));

    list->head = NULL;
    list->size = 0;

    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index)
{
    struct Node *temp = obj->head;

    if (index < 0 || index >= obj->size)
        return -1;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->val = val;
    newnode->next = obj->head;

    obj->head = newnode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->val = val;
    newnode->next = NULL;

    if (obj->head == NULL)
    {
        obj->head = newnode;
    }
    else
    {
        struct Node *temp = obj->head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    if (index < 0 || index > obj->size)
        return;

    if (index == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    struct Node *temp = obj->head;

    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->val = val;
    newnode->next = temp->next;
    temp->next = newnode;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    if (index < 0 || index >= obj->size)
        return;

    struct Node *temp = obj->head;

    if (index == 0)
    {
        obj->head = temp->next;
        free(temp);
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        struct Node *del = temp->next;
        temp->next = del->next;
        free(del);
    }

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj)
{
    struct Node *temp;

    while (obj->head != NULL)
    {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }

    free(obj);
}
