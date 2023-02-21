// Queue-Array
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Queue
{
    int array[SIZE];
    int front, rear;
} Queue;

void initQueue();
void enqueue(int value);
int dequeue();
int display();

Queue *queue;

int main()
{
    initQueue();

    enqueue(11);
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    enqueue(16);

    printf("\n");

    printf("%d : Dequeued\n", dequeue());
    printf("%d : Dequeued\n", dequeue());
    printf("%d : Dequeued\n", dequeue());

    display();

    enqueue(16);
}

void initQueue()
{
    queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
}

void enqueue(int value)
{

    if (queue->rear == SIZE - 1)
    {
        printf("\nQueue Overflow\n");
        return;
    }

    if (queue->front == -1)
        queue->front = 0;

    queue->rear++;
    queue->array[queue->rear] = value;

    printf("%d : Enqueued\n", value);
}

int dequeue()
{

    if (queue->front == -1)
    {
        printf("Queue Underflow\n");
        return 0;
    }

    int value = queue->array[queue->front];
    queue->front++;

    if (queue->front > queue->rear)
        queue->front = queue->rear = 0;

    return value;
}

int display()
{
    printf("\nDisplay: ");
    if (queue->rear != 0)
    {
        for (int i = queue->front; i <= queue->rear; i++)
        {
            printf("%d ", queue->array[i]);
        }
    }
}