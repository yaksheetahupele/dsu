/*1. Write a Menu driven C code for following operations,
● Insert at Beginning
● Insert at End
● Insert After a a node
● Insert Before a Given Node.
● Insert at a specific node
● Count Total Nodes.
● Find the Largest Node.
● Find the Smallest Node.
● Display Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at Beginning
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

// Insert at End
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

// Insert After a Given Node
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

// Insert Before a Given Node
void insertBefore()
{
    struct Node *newNode, *temp, *prev;
    int value, search;

    printf("Enter node value before which to insert: ");
    scanf("%d", &search);

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // If inserting before first node
    if (head->data == search)
    {
        insertBeginning();
        return;
    }

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != search)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = temp;
    prev->next = newNode;
}

// Insert at Specific Position
void insertPosition()
{
    struct Node *newNode, *temp;
    int value, position, i;

    printf("Enter position: ");
    scanf("%d", &position);

    if (position == 1)
    {
        insertBeginning();
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Count Total Nodes
void countNodes()
{
    struct Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total nodes = %d\n", count);
}

// Find Largest Node
void largest()
{
    struct Node *temp;
    int max;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    max = head->data;

    while (temp != NULL)
    {
        if (temp->data > max)
            max = temp->data;

        temp = temp->next;
    }

    printf("Largest node = %d\n", max);
}

// Find Smallest Node
void smallest()
{
    struct Node *temp;
    int min;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    min = head->data;

    while (temp != NULL)
    {
        if (temp->data < min)
            min = temp->data;

        temp = temp->next;
    }

    printf("Smallest node = %d\n", min);
}

// Display Linked List
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

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Insert Before a Given Node\n");
        printf("5. Insert at a Specific Position\n");
        printf("6. Count Total Nodes\n");
        printf("7. Find Largest Node\n");
        printf("8. Find Smallest Node\n");
        printf("9. Display Linked List\n");
        printf("10. Exit\n");

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
            insertBefore();
            break;

        case 5:
            insertPosition();
            break;

        case 6:
            countNodes();
            break;

        case 7:
            largest();
            break;

        case 8:
            smallest();
            break;

        case 9:
            display();
            break;

        case 10:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 10);

    return 0;
}