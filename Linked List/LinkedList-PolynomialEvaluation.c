// LinkedList-PolynomialEvaluation
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    int coefficient;
    int power;
    struct Node *next;
} Node;

Node *createNode(int coefficient, int power);
void insert(Node **, Node *);
Node *addPolynomial(Node *, Node *, int x);
int evaluate(Node *, int x);
void display(Node *);

int main()
{
    Node *poly1 = NULL, *poly2 = NULL;
    insert(&poly1, createNode(2, 6));
    insert(&poly1, createNode(-1, 3));
    insert(&poly1, createNode(4, 2));
    insert(&poly1, createNode(-15, 1));
    printf("Polynomial 1: ");
    display(poly1);
    insert(&poly2, createNode(5, 5));
    insert(&poly2, createNode(-6, 3));
    insert(&poly2, createNode(-5, 2));
    insert(&poly2, createNode(20, 1));
    printf("Polynomial 2: ");
    display(poly2);
    printf("Enter Value of X: ");
    int x;
    scanf("%d", &x);
    addPolynomial(poly1, poly2, x);
    return 0;
}

Node *createNode(int coefficient, int power)
{
    Node *temp = malloc(sizeof(Node));
    temp->coefficient = coefficient;
    temp->power = power;
    temp->next = NULL;
    return temp;
}

void insert(Node **list, Node *newNode)
{
    Node *temp = *list;
    if (temp == NULL)
    {
        *list = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node *addPolynomial(Node *list1, Node *list2, int x)
{
    Node *list3 = NULL, *curr = list3;
    while (list1 != NULL && list2 != NULL)
    {
        if (curr == NULL)
        {
            curr = createNode(0, 0);
            list3 = curr;
        }
        else
        {
            curr->next = createNode(0, 0);
            curr = curr->next;
        }
        if (list1->power > list2->power)
        {
            curr->power = list1->power;
            curr->coefficient = list1->coefficient;
            list1 = list1->next;
        }
        else if (list1->power < list2->power)
        {
            curr->power = list2->power;
            curr->coefficient = list2->coefficient;
            list2 = list2->next;
        }
        else
        {
            curr->power = list1->power;
            curr->coefficient = list1->coefficient + list2->coefficient;
            list1 = list1->next;
            list2 = list2->next;
        }
    }
    while (list1 != NULL || list2 != NULL)
    {
        if (curr == NULL)
            curr = createNode(0, 0);
        else
        {
            curr->next = createNode(0, 0);
            curr = curr->next;
        }
        if (list1 != NULL)
        {
            curr->power = list1->power;
            curr->coefficient = list1->coefficient;
            list1 = list1->next;
        }
        if (list2 != NULL)
        {
            curr->power = list2->power;
            curr->coefficient = list2->coefficient;
            list1 = list2->next;
        }
    }
    printf("\nPolynomial Addition: ");
    display(list3);
    printf("\nAnswer: %d", evaluate(list3, x));
}

int evaluate(Node *list, int x)
{
    int ans = 0;
    while (list != NULL)
    {
        ans += list->coefficient * pow(x, list->power);
        list = list->next;
    }
    return ans;
}

void display(Node *polyList)
{
    if (polyList == NULL)
        printf("Polynomial Empty!");
    else
    {
        Node *temp = polyList;
        while (temp != NULL)
        {
            if (temp->coefficient > 0 && temp != polyList)
                printf("+");
            printf(" %dx^%d ", temp->coefficient, temp->power);
            temp = temp->next;
        }
    }
    printf("\n");
}