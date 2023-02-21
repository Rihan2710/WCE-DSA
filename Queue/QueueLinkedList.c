#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value);
int dequeue();
void display();
void retrieveFront();

int main()
{

    enqueue(1);
    enqueue(19);
    enqueue(12);
    enqueue(13);

    printf("\n");

    printf("%d : Dequeued\n", dequeue());
    printf("%d : Dequeued\n", dequeue());
    printf("%d : Dequeued\n", dequeue());

    display();

    retrieveFront();
    display();
}

void enqueue(int value)
{
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    ptr->data = value;
    ptr->next = NULL;

    if ((front == NULL) && (rear == NULL))
    {
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }

    printf("%d : Enqueued\n", value);
}

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else
    {
        Node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}

void display()
{
    printf("\nDisplay: ");
    Node *temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = front;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void retrieveFront()
{
    Node *temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("\n\n%d : Front\n", front->data);
    }
}
