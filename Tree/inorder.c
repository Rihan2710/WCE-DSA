#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int item)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=item;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

struct node* insertLeft(struct node* root,int item)
{
    root->left=create(item);
    return root->left; 
}
struct node* insertRight(struct node* root,int item)
{
    root->right=create(item);
    return root->right; 
}

void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf(" %d ->",root->data);
    inorder(root->right);
}

void main()
{
    struct node* root = create(5);
    insertLeft(root, 8);
    insertRight(root, 2);
    insertLeft(root->left, 3);
    insertRight(root->right, 7);
    insertLeft(root->left, 4);
    insertRight(root->right, 1);
    printf("Inorder : ");
    inorder(root);
}

