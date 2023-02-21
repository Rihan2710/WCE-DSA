#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;

void frontInsert(int);
void rearInsert(int);
void midInsert(int,int);
void frontDelete(int);
void rearDelete(int);
void midDelete(int);
void display();
// void concate();
void reverse();


void main()
{
    int n,l,choice;
    // int L1[]={2,4,6,1,7};
    // int L2[]={9,2,5,8};
    while (1)
    {   printf("\n1.Front Insert\n2.Rear Insert\n3.Mid Insert\n4.Front Delete\n5.Rear Delete\n6.Mid Delete\n7.Display\n8.Concatenate\n9.Reverse\n10.Exit");
        printf("\nEnter your choice :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: 
            printf("\nInsert in Front: "); 
            scanf("%d",&n); 
            frontInsert(n); 
            break; 
        case 2: 
            printf("\nInsert in Rear: "); 
            scanf("%d",&n); 
            rearInsert(n); 
            break; 
        case 3: 
            printf("\nInsert in Mid: "); 
            scanf("%d",&n);
            printf("Enter the location:");
            scanf("%d",&l); 
            midInsert(n,l); 
            break; 
        case 4: 
            printf("\nDelete in Front: "); 
            scanf("%d",&n); 
            frontDelete(n); 
            break;
        case 5: 
            printf("\nDelete in Rear: "); 
            scanf("%d",&n); 
            rearDelete(n); 
            break;
        case 6: 
            printf("Enter the location:");
            scanf("%d",&l); 
            midDelete(l); 
            break;   
        case 7: 
            display(); 
            break; 
        case 8:
            // concate();
            break;
        case 9:
            reverse();
            break;
        case 10: 
            printf("\nExitted Successfuly");
            exit(0); 
        default: 
            printf("\nPlease enter valid choice"); 
        }
    }
}

void frontInsert(int item)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        ptr->data=item;
        ptr->next=head;
        head = ptr;
        printf("\nFront");
    }
}

void rearInsert(int item)
{
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node ));
    if(ptr==NULL)
        printf("\nOverflow");
    else
    {
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next=NULL;
            head=ptr;
            printf("\nRear If");
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("\nRear Else");
        }
    }
}

void midInsert(int item , int loc)
{
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node ));
    if(ptr==NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        ptr->data=item;
        temp=head;
        for(int i=0;i<loc;i++)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("Can't Insert");
                return;
            }
        }
            ptr->next=temp->next;
            temp->next=ptr;
            printf("\nMid Insert");       
    }
}

void frontDelete(int item)
{
    struct node *ptr;
    if(head==NULL)
        printf("\nEmpty");
    else
    {
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("\n%d Node Deleted in Front",ptr);
    }
}

void rearDelete(int item)
{
    struct node *ptr,*ptr1;
    if(head==NULL)
        printf("\nEmpty");
    else if (head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("\n%d Only Node deleted",head);
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
        printf("\n%d Node Deleted in Rear",ptr);
    }
}

void midDelete(int loc)
{
    struct node *ptr,*ptr1;
    ptr=head;
    for(int i=0;i<loc;i++)
    {
        ptr1=ptr;
        ptr=ptr->next;
        if(ptr==NULL)
        {
            printf("\nCan't Delete");
            return;
        }
    }
    ptr1->next=ptr->next;
    free(ptr);
    printf("\nDeleted : %d",loc+1);
}

void display()
{
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf(" %d|",ptr->data,"\n");
            ptr=ptr->next;
        }
    }
}

// void concate(struct node *a,struct node *b)
// {

// }

void reverse()
{
    // struct node *ptr;
    struct node *ptr=NULL;
    struct node *cru=head;
    struct node *temp;
    while(cru)
    {
        temp=cru->next;
        cru->next=ptr;
        ptr=cru;
        cru=temp;
    }
     printf(" %d",ptr);
}