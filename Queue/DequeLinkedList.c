#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev, *next;
} Node;

Node *createNode(int data);
void createSentinels();
void enqueueAtFront(int data);
void enqueueAtRear(int data);
void dequeueAtFront();
void dequeueAtRear();
void display();

Node *head = NULL, *tail = NULL;

int main()
{
    createSentinels();

    enqueueAtFront(90);
    enqueueAtFront(20);

    display();

    enqueueAtRear(10);
    

    display();

    dequeueAtFront();
    dequeueAtRear();

    display();
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return (newNode);
}

void createSentinels()
{
    head = createNode(0);
    tail = createNode(0);
    head->next = tail;
    tail->prev = head;
}

void enqueueAtFront(int data)
{
    Node *newNode, *temp;
    newNode = createNode(data);
    temp = head->next;
    head->next = newNode;
    newNode->prev = head;
    newNode->next = temp;
    temp->prev = newNode;
}

void enqueueAtRear(int data)
{
    Node *newNode, *temp;
    newNode = createNode(data);
    temp = tail->prev;
    tail->prev = newNode;
    newNode->next = tail;
    newNode->prev = temp;
    temp->next = newNode;
}

void dequeueAtFront()
{
    Node *temp;
    if (head->next == tail)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        free(temp);
    }
    return;
}

void dequeueAtRear()
{
    Node *temp;
    if (tail->prev == head)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = tail->prev;
        tail->prev = temp->prev;
        temp->prev->next = tail;
        free(temp);
    }
    return;
}

void display()
{
    Node *temp;

    if (head->next == tail)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = head->next;
    while (temp != tail)
    {
        printf("%-3d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}