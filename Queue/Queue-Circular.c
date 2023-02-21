// Queue-Circular
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct CircularQueue
{
  int array[SIZE];
  int front, rear;
} CircularQueue;

void initQueue();
int isFull();
int isEmpty();
void enQueue(int val);
int deQueue();
void display();

CircularQueue *queue;

int main()
{

  initQueue();

  deQueue();

  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  enQueue(6);

  display();
  deQueue();

  display();

  enQueue(7);
  display();

  enQueue(8);

  return 0;
}

void initQueue()
{
  queue = (CircularQueue *)malloc(sizeof(CircularQueue));
  queue->front = -1;
  queue->rear = -1;
}

int isFull()
{
  if ((queue->front == queue->rear + 1) || (queue->front == 0 && queue->rear == SIZE - 1))
    return 1;
  return 0;
}

int isEmpty()
{
  if (queue->front == -1)
    return 1;
  return 0;
}

void enQueue(int val)
{
  if (isFull(queue))
    printf("\nQueue Overflow! \n");
  else
  {
    if (queue->front == -1)
      queue->front = 0;
    queue->rear = (queue->rear + 1) % SIZE;
    queue->array[queue->rear] = val;
    printf("\n%d : Enqueued", val);
  }
}

int deQueue()
{
  int val;
  if (isEmpty(queue))
  {
    printf("\nQueue Underflow! \n");
    return (-1);
  }
  else
  {
    val = queue->array[queue->front];
    if (queue->front == queue->rear)
    {
      queue->front = -1;
      queue->rear = -1;
    }
    else
    {
      queue->front = (queue->front + 1) % SIZE;
    }
    printf("\n%d : Dequeued\n", val);
    return (val);
  }
}

void display()
{
  int i;
  if (isEmpty(queue))
    printf(" \nEmpty Queue\n");
  else
  {
    printf("\nDisplay: ");
    for (i = queue->front; i != queue->rear; i = (i + 1) % SIZE)
    {
      printf("%d ", queue->array[i]);
    }
    printf("%d ", queue->array[i]);
  }
}
