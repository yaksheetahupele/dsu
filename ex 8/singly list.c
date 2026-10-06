// Insert at beginning
// Insert at end
// Insert after a specific node
// Search
// Display

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeginning()
{
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd()
{
    struct Node *newNode, *temp;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

// Insert after a specific node
void insertAfter()
{
    struct Node *newNode, *temp;
    int value, search;

    printf("Enter node value after which to insert: ");
    scanf("%d", &search);

    temp = head;

    while (temp != NULL && temp->data != search)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Search
void search()
{
    struct Node *temp;
    int value, position = 1;

    printf("Enter value to search: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Element found at position %d\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element not found\n");
}

// Display
void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
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
    int choice;

    do
    {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Specific Node\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertBeginning();
            break;

        case 2:
            insertEnd();
            break;

        case 3:
            insertAfter();
            break;

        case 4:
            search();
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Exiting...");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}