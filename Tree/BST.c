#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} TreeNode;
TreeNode *createNode(int data);
TreeNode *InsertNode(TreeNode *, int data);
void search(TreeNode *, int key);
void inOrder(TreeNode *);
int FindMin(TreeNode *);
int FindMax(TreeNode *);

TreeNode *createNode(int data)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
TreeNode *InsertNode(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = InsertNode(root->left, data);
    }
    else
    {
        root->right = InsertNode(root->right, data);
    }
    return root;
}

void search(TreeNode *root, int key)
{
    if (root == NULL)
    {
        printf("\nKey Not Found");
    }
    else if (root->data == key)
    {
        printf("\nKey Found %d",key);
    }
    else
    {
        if (key < root->data)
        {
            search(root->left, key);
        }
        else
        {
            search(root->right, key);
        }
    }
    return;
}

void inOrder(TreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int FindMin(TreeNode *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return (root->data);
}

int FindMax(TreeNode *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return (root->data);
}
int main()
{
    TreeNode *root = NULL;
    root = InsertNode(root, 25);
    root = InsertNode(root, 29);
    root = InsertNode(root, 38);
    root = InsertNode(root, 73);
    root = InsertNode(root, 78);
    root = InsertNode(root, 85);
    root = InsertNode(root, 45);

    inOrder(root);
    search(root, 38);
    search(root, 73);
    search(root, 45);
    printf("\nMinimum : %d", FindMin(root));
    printf("\nMaximum : %d", FindMax(root));
    return 0;
}