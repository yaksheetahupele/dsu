/*Write a C Program to Implement Singly Linked List with
Operations:
(i) Delete at Beginning
(ii) Delete at End
(iii) Delete After
(iv) Display*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Delete at Beginning
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning\n");
}

// Delete at End
void deleteEnd()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Node deleted from end\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Node deleted from end\n");
}

// Delete After a Specific Node
void deleteAfter()
{
    struct Node *temp, *del;
    int value;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter node value after which to delete: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    if (temp->next == NULL)
    {
        printf("No node exists after %d\n", value);
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node deleted successfully\n");
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
    int choice, n, i, value;
    struct Node *newNode, *temp;

    // Create initial linked list
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
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

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Delete at Beginning\n");
        printf("2. Delete at End\n");
        printf("3. Delete After\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deleteBeginning();
            break;

        case 2:
            deleteEnd();
            break;

        case 3:
            deleteAfter();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}