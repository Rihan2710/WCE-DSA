#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int coeff;
    int pow;
    struct Node *next;
} Node;

void createNode(int x, int y, Node **temp);
void polyAdd(Node *p1, Node *p2, Node *result);
void display(Node *node);

void createNode(int x, int y, Node **temp)
{
    Node *r, *z;
    z = *temp;
    if (z == NULL)
    {
        r = (Node *)malloc(sizeof(Node));
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = (Node *)malloc(sizeof(Node));
        r = r->next;
        r->next = NULL;
    }
    else
    {
        r->coeff = x;
        r->pow = y;
        r->next = (Node *)malloc(sizeof(Node));
        r = r->next;
        r->next = NULL;
    }
}
void polyAdd(Node *p1, Node *p2, Node *result)
{
    while (p1->next && p2->next)
    {
        if (p1->pow > p2->pow)
        {
            result->pow = p1->pow;
            result->coeff = p1->coeff;
            p1 = p1->next;
        }
        else if (p1->pow < p2->pow)
        {
            result->pow = p2->pow;
            result->coeff = p2->coeff;
            p2 = p2->next;
        }
        else
        {
            result->pow = p1->pow;
            result->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        result->next = (Node *)malloc(sizeof(Node));
        result = result->next;
        result->next = NULL;
    }
    while (p1->next || p2->next)
    {
        if (p1->next)
        {
            result->pow = p1->pow;
            result->coeff = p1->coeff;
            p1 = p1->next;
        }
        if (p2->next)
        {
            result->pow = p2->pow;
            result->coeff = p2->coeff;
            p2 = p2->next;
        }
        result->next = (Node *)malloc(sizeof(Node));
        result = result->next;
        result->next = NULL;
    }
}

void display(Node *node)
{
    while (node->next != NULL)
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->next != NULL)
            printf(" + ");
    }
    printf("\n");
}
int main()
{
    Node *p1 = NULL, *p2 = NULL, *result = NULL;

    createNode(1, 7, &p1);
    createNode(33, 5, &p1);
    createNode(5, 2, &p1);
    createNode(21, 5, &p2);
    createNode(15, 0, &p2);

    printf("First Polynomial: ");
    display(p1);

    printf("\nSecond Polynomial: ");
    display(p2);

    result = (Node *)malloc(sizeof(Node));
    polyAdd(p1, p2, result);
    printf("\nPolynomial Addition: ");
    display(result);

    return 0;
}