#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void reverse(Node **head_ref)
{
    Node *prev = NULL;
    Node *current = *head_ref;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;

        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void push(Node **head_ref, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    Node *head = NULL;

    push(&head, 90);
    push(&head, 40);
    push(&head, 15);
    push(&head, 35);

    printf("Given linked list\n");
    printList(head);
    reverse(&head);
    printf("\nReversed linked list \n");
    printList(head);
    getchar();
}
