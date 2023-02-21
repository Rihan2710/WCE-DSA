#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertBegin(Node **, int value);
void insertEnd(Node **, int value);
void insertAtPosition(Node **, int value, int pos);
void deleteBegin(Node **);
void deleteEnd(Node **);
void deleteFromPosition(Node **, int pos);
void display(Node *);

int size = 0;

int main()
{
    Node *head = NULL;

    insertBegin(&head, 99);
    insertBegin(&head, 7);
    insertBegin(&head, 75);

    insertEnd(&head, 2);
    insertEnd(&head, 7);

    insertAtPosition(&head, 7, 5);

    deleteFromPosition(&head, 3);
    display(head);
}
void insertBegin(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    size++;
}

void insertEnd(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    Node *lastNode = *head;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;

    size++;
}

void insertAtPosition(Node **head, int value, int pos)
{
    if (*head == NULL)
    {
        printf("Linked List is Empty");
        return;
    }

    if (pos < 1)
    {
        printf("Invalid Position");
        return;
    }

    while (pos--)
    {
        if (pos == 0)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = value;
            newNode->next = *head;
            *head = newNode;
        }
        else
            head = &(*head)->next;
    }

    size++;
}

void deleteBegin(Node **head)
{
    if (*head == NULL)
    {
        printf("Linked List is Empty");
        return;
    }

    Node *tempNode = (Node *)malloc(sizeof(Node));
    tempNode = *head;
    *head = tempNode->next;
    free(tempNode);
    size--;
}

void deleteEnd(Node **head)
{
    if (*head == NULL)
    {
        printf("Linked List is Empty");
        return;
    }

    Node *lastNode = *head;
    Node *secondLastNode;

    while (lastNode->next != NULL)
    {
        secondLastNode = lastNode;
        lastNode = lastNode->next;
    }
    secondLastNode->next = NULL;
    free(lastNode);
    size--;
}

void deleteFromPosition(Node **head, int pos)
{
    if (*head == NULL)
    {
        printf("Linked List is Empty");
        return;
    }

    if (pos < 1)
    {
        printf("Invalid Position");
        return;
    }

    Node *temp = *head;
    Node *temp1;
    while (--pos)
    {
        temp1 = temp;
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Item Not Found\n");
            return;
        }
    }

    temp1->next = temp->next;
    free(temp);

    size--;
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("Data: %d\n", head->data);
        head = head->next;
    }
}