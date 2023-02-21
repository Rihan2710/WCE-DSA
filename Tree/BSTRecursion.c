#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int data);
void printInorder(Node *);
int main()
{
    Node *root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    root->right->right = newNode(9);

    printf("Inorder traversal of binary tree is \n");
    printInorder(root);
}
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void printInorder(Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
