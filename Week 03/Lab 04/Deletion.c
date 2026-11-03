
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void beginsert(int item)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }

    newnode->data = item;
    newnode->next = head;
    head = newnode;

    printf("Node inserted\n");
}

void begin_delete()
{
    struct node *ptr;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    ptr = head;
    head = ptr->next;
    free(ptr);

    printf("Node deleted from beginning\n");
}

void last_delete()
{
    struct node *ptr, *ptr1;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Only node deleted\n");
        return;
    }

    ptr = head;

    while (ptr->next != NULL)
    {
        ptr1 = ptr;
        ptr = ptr->next;
    }

    ptr1->next = NULL;
    free(ptr);

    printf("Node deleted from end\n");
}

void random_delete()
{
    struct node *ptr, *ptr1;
    int location, i;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter location: ");
    scanf("%d", &location);

    if (location < 1)
    {
        printf("Invalid location\n");
        return;
    }

    ptr = head;

    for (i = 0; i < location - 1; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("Can't delete\n");
            return;
        }
    }

    ptr1->next = ptr->next;
    free(ptr);

    printf("Node deleted\n");
}

void display()
{
    struct node *ptr;

    ptr = head;

    if (ptr == NULL)
    {
        printf("Nothing to print\n");
        return;
    }

    printf("Linked List: ");

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

int main()
{
    printf("Jeevan balaji, 1WA25CS103, 3/11/2026");
    int choice, item;

    choice = 0;

    while (choice != 6)
    {
        printf("\n----- Singly Linked List Menu -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Specified Location\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                beginsert(item);
                break;

            case 2:
                begin_delete();
                break;

            case 3:
                last_delete();
                break;

            case 4:
                random_delete();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

