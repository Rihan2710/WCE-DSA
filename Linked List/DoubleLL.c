#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *prev, *next;
} Node;

void insertFront(int value);
void insertRear(int value);
void insertAtPosition(int value, int pos);
void deleteFirst();
void deleteRear();
void deleteFromPosition(int pos);
void display();

Node *head = NULL;

int main()
{
    display();

    insertFront(40);
    insertFront(31);
    insertFront(78);
    insertFront(89);

    insertRear(52);
    insertRear(7);

    insertAtPosition(4, 4);

    display();

    deleteFirst();
    deleteRear();
    deleteFromPosition(1);

    display();
}

void insertFront(int value)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->prev = NULL;

    temp->next = head;
    head = temp;
}

void insertRear(int value)
{
    Node *temp, *trav;
    temp = (Node *)malloc(sizeof(Node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = value;
    temp->next = NULL;
    trav = head;

    if (head == NULL)
    {

        head = temp;
    }

    else
    {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}

void insertAtPosition(int value, int pos)
{
    int i = 1;
    Node *temp, *newNode;
    newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
    }

    else if (pos == 1)
    {
        insertFront(value);
    }

    else
    {
        newNode->data = value;
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        temp->next->prev = newNode;
    }
}

void deleteFirst()
{
    Node *temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }
}

void deleteRear()
{
    if (head == NULL)
        printf("\nList is empty\n");

    Node *temp = head, *prevNode;

    while (temp->next != NULL)
    {
        prevNode = temp;
        temp = temp->next;
    }
    free(temp); // t will delete the last node
    prevNode->next = NULL;

    // while (temp->next != NULL)
    //     temp = temp->next;
    // if (head->next == NULL)
    //     head = NULL;
    // else
    // {
    //     temp->prev->next = NULL;
    //     free(temp);
    // }
}

void deleteFromPosition(int pos)
{
    int i = 1;
    Node *temp, *position;
    temp = head;

    if (head == NULL)
        printf("\nList is empty\n");

    else
    {

        if (pos == 1)
        {
            deleteFirst();
            if (head != NULL)
            {
                head->prev = NULL;
            }
            free(position);
            return;
        }

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        position = temp->next;
        if (position->next != NULL)
            position->next->prev = temp;
        temp->next = position->next;

        free(position);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    Node *temp;
    temp = head;

    printf("\n");

    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }

    printf("\n");
}