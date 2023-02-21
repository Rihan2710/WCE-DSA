// LinkedList-Circular
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertAtFront(int data);
void insertAtRear(int data);
void insertAtPosition(int data, int pos);
void deleteFront();
void deleteRear();
void deleteAtPosition(int pos);
void display();

Node *head = NULL;

int main()
{
    insertAtFront(30);
    insertAtFront(20);
    insertAtFront(10);

    insertAtRear(50);
    insertAtRear(60);

    insertAtPosition(40, 5);

    deleteFront();
    deleteRear();
    deleteAtPosition(1);

    display();

    return 0;
}

void insertAtFront(int data)
{
    struct Node *temp;
    temp = (Node *)malloc(sizeof(Node));

    if (head == NULL)
    {
        temp->data = data;
        temp->next = temp;
        head = temp;
    }
    else
    {
        temp->data = data;
        temp->next = head->next;
        head->next = temp;
    }
}

void insertAtRear(int data)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));

    if (head == NULL)
    {
        temp->data = data;
        temp->next = temp;
        head = temp;
    }
    else
    {
        temp->data = data;
        temp->next = head->next;
        head->next = temp;
        head = temp;
    }
}

void insertAtPosition(int data, int pos)
{
    Node *newNode, *curNode;
    int i;

    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        curNode = head;
        for (i = 0; i <= pos - 3; i++)
        {
            curNode = curNode->next;
        }
        newNode->next = curNode->next;
        curNode->next = newNode;
    }
}

void deleteFront()
{
    Node *temp;

    if (head == NULL)
        printf("\nList is empty.\n");

    else
    {
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }
}

void deleteRear()
{
    Node *temp;

    if (head == NULL)
        printf("\nList is empty.\n");

    temp = head->next;

    while (temp->next != head)
        temp = temp->next;

    temp->next = head->next;
    head = temp;
}

void deleteAtPosition(int pos)
{
    Node *u, *v;
    int w = 0;
    u = head;
    while (w != pos)
    {
        v = u;
        u = u->next;
        w++;
    }
    v->next = u->next;
    free(u);
}

void display()
{
    if (head == NULL)
        printf("\nList is empty\n");

    else
    {
        Node *temp;
        temp = head->next;
        do
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;
        } while (temp != head->next);
    }
}
