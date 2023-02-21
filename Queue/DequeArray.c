// Queue-DequeArray
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct Deque
{
    int array[SIZE];
    int front, rear;
} Deque;

void initDeque();
void insertFront(int value);
void insertRear(int value);
void deleteFront();
void deleteRear();
int count();
void display();

Deque *queue;

int main()
{
    initDeque();

    insertFront(70);
    insertFront(20);
    insertRear(90);
    insertRear(40);
    insertFront(80);

    display();
}

void initDeque()
{
    queue = (Deque *)malloc(sizeof(Deque));
    queue->front = -1;
    queue->rear = -1;
    for (int i = 0; i < SIZE; i++)
    {
        queue->array[i] = 0;
    }
}

void insertFront(int value)
{
    int i, k, c;

    if (queue->front == 0 && queue->rear == SIZE - 1)
    {
        printf("\nDeque Overflow\n");
        return;
    }

    if (queue->front == -1)
    {
        queue->front = queue->rear = 0;
        queue->array[queue->front] = value;
        printf("%d : Front Insert\n", value);
        return;
    }

    if (queue->rear != SIZE - 1)
    {
        c = count(queue);
        k = queue->rear + 1;

        for (int i = 1; i <= c; i++)
        {
            queue->array[k] = queue->array[k - 1];
            k--;
        }

        queue->array[k] = value;
        queue->front = k;
        queue->rear++;
    }
    else
    {
        queue->front--;
        queue->array[queue->front] = value;
    }

    printf("%d : Front Insert\n", value);
}

void insertRear(int value)
{
    int k;

    if (queue->front == 0 && queue->rear == SIZE - 1)
    {
        printf("\nDeque Overflow\n");
        return;
    }

    if (queue->front == -1)
    {
        queue->rear = queue->front = 0;
        queue->array[queue->rear] = value;
        printf("%d : Rear Insert\n", value);
        return;
    }

    if (queue->rear == SIZE - 1)
    {
        k = queue->front - 1;
        for (int i = queue->front - 1; i < queue->rear; i++)
        {
            k = i;
            if (k == SIZE - 1)
                queue->array[k] = 0;
            else
                queue->array[k] = queue->array[i + 1];
        }
        (queue->rear)--;
        (queue->front)--;
    }
    (queue->rear)++;
    queue->array[queue->rear] = value;

    printf("%d : Rear Insert\n", value);
}

void deleteFront()
{
    int item;

    if (queue->front == -1)
    {
        printf("\nDeque Underflow\n");
        return;
    }

    item = queue->array[queue->front];
    queue->array[queue->front] = 0;

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        (queue->front)++;

    printf("%d : Front Delete\n", item);
}

void deleteRear()
{
    int item;

    if (queue->front == -1)
    {
        printf("\nDeque Underflow\n");
        return;
    }

    item = queue->array[queue->rear];

    queue->array[queue->rear] = 0;

    queue->rear--;

    if (queue->rear == -1)
        queue->front = -1;

    printf("%d : Rear Delete\n", item);
}

void display()
{
    printf("\nFront: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", queue->array[i]);
    printf(": Rear");
}

int count()
{
    int value = 0;
    for (int i = 0; i < SIZE; i++)
        if (queue->array[i] != 0)
            value++;

    return value;
}
