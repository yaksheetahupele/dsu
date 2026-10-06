/*1. Write a Menu driven C code for following operations,
● DeleteInsert at Beginning
● Insert at End
● Insert After a a node
● Insert Before a Given Node.
● Insert at a specific node
● Delete Node by Value.*/

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
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert After a Node
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

// Delete Node by Value
void deleteByValue()
{
    struct Node *temp, *prev;
    int value;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    // If first node contains the value
    if (head->data == value)
    {
        temp = head;
        head = head->next;
        free(temp);

        printf("Node deleted\n");
        return;
    }

    temp = head;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted\n");
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
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Insert Before a Given Node\n");
        printf("5. Insert at Specific Position\n");
        printf("6. Delete Node by Value\n");
        printf("7. Display\n");
        printf("8. Exit\n");

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
            deleteByValue();
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 8);

    return 0;
}