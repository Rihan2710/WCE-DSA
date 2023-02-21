#include <stdio.h>
#include <malloc.h>
typedef struct Node
{
    int priority;
    int info;
    struct Node *link;
} Node;
void insert(int data, int priority);
void delete();
void display();

Node *front = NULL;

int main()
{

    insert(12, 4);
    insert(89, 7);
    insert(194, 8);
    insert(5, 1);

    display();

    delete ();

    display();
}

void insert(int data, int priority)
{
    Node *temp, *q;

    temp = (Node *)malloc(sizeof(Node));
    temp->info = data;
    temp->priority = priority;
    if (front == NULL || priority < front->priority)
    {
        temp->link = front;
        front = temp;
    }
    else
    {
        q = front;
        while (q->link != NULL && q->link->priority <= priority)
            q = q->link;
        temp->link = q->link;
        q->link = temp;
    }
}

void delete()
{
    Node *temp;
    if (front == NULL)
        printf("Queue Underflow\n");
    else
    {
        temp = front;
        printf("Deleted item is %d\n", temp->info);
        front = front->link;
        free(temp);
    }
}

void display()
{
    Node *ptr;
    ptr = front;
    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is :\n");
        printf("Priority    Item\n");
        while (ptr != NULL)
        {
            printf("%5d    %5d\n", ptr->priority, ptr->info);
            ptr = ptr->link;
        }
    }
}