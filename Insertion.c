
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int data)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void append(int data)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void insert_at_position(int data, int position)
{
    struct node *newnode, *temp;
    int i;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = data;

    if (position == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    if (position < 1)
    {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newnode);
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display()
{
    struct node *temp;

    temp = head;

    if (temp == NULL)
    {
        printf("Empty List\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    printf("Jeevan balaji, 1WA25CS103, 3/11/2026");

    int choice, data, position;

    choice = 0;

    while (choice != 4)
    {
        printf("\n----- Singly Linked List Menu -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                display();
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                append(data);
                display();
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &position);

                insert_at_position(data, position);
                display();
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


