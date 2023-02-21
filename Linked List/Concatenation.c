#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create(int A[], int n);
void display(Node *);
void concat(Node *, Node *);

Node *temp = NULL, *first = NULL, *second = NULL;

int main()
{
    int A[] = {1, 3, 4, 6};
    int B[] = {2, 4, 5, 7};
    first = create(A, 4);
    second = create(B, 4);

    printf("First Linked List: ");
    display(first);

    printf("\nSecond Linked List: ");
    display(second);

    concat(first, second);

    printf("\n\nConcatenated Linked List: ");
    display(first);
}

Node *create(int A[], int n)
{
    int i;
    Node *t, *last;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = A[0];
    temp->next = NULL;
    last = temp;

    for (i = 1; i < n; i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return temp;
}

void display(Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void concat(Node *first, Node *second)
{
    Node *p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = second;
    second = NULL;
}