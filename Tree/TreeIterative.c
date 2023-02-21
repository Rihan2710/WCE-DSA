#include <stdio.h>
#include <stdlib.h>
#define bool int
typedef struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;
} tNode;
typedef struct sNode
{
    struct tNode *t;
    struct sNode *next;
} sNode;
void push(sNode **top_ref, tNode *t);
tNode *pop(sNode **top_ref);
bool isEmpty(sNode *top);
void inOrder(tNode *root)
{
    tNode *current = root;
    sNode *s = NULL;
    bool done = 0;
    while (!done)
    {
        if (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                printf("%d ", current->data);
                current = current->right;
            }
            else
                done = 1;
        }
    }
}
void push(sNode **top_ref, tNode *t)
{

    sNode *new_tNode = (sNode *)malloc(sizeof(sNode));

    if (new_tNode == NULL)
    {
        printf("Stack Overflow \n");
        getchar();
        exit(0);
    }

    new_tNode->t = t;
    new_tNode->next = (*top_ref);
    (*top_ref) = new_tNode;
}

bool isEmpty(sNode *top)
{
    return (top == NULL) ? 1 : 0;
}
tNode *pop(sNode **top_ref)
{
    tNode *res;
    sNode *top;

    if (isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}
tNode *newtNode(int data)
{
    tNode *tNode_ = (tNode *)malloc(sizeof(tNode));
    tNode_->data = data;
    tNode_->left = NULL;
    tNode_->right = NULL;
    return (tNode_);
}
int main()
{
    tNode *root = newtNode(1);
    root->left = newtNode(3);
    root->right = newtNode(5);
    root->right->left = newtNode(7);
    root->left->right = newtNode(11);
    inOrder(root);
}
