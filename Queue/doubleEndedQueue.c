#include<stdio.h>
#include<stdlib.h>
#define max 100
void rearAdd(int);
void frontAdd(int);
void rearDel(int);
void frontDel(int);
void display();

int dque[max];
int rear=-1,front=0,t=0,choice,n,i,x; 
void main()
{  
    printf("\nPress - 1 to Insert in Rear  "); 
    printf("\nPress - 2 to Delete in Rear "); 
    printf("\nPress - 3 to Insert in Front "); 
    printf("\nPress - 4 to Delete in Front ");
    printf("\nPress - 5 to Display");
    while (1)
    {
        printf("\nEnter your choice :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: 
            printf("\nEnter element to insert in rear : "); 
            scanf("%d",&n); 
            rearAdd(n); 
            break; 
        case 2: 
            printf("\nEnter element to delete in rear : "); 
            scanf("%d",&n); 
            rearDel(n); 
            break; 
        case 3:
            printf("\nEnter element to insert in front : "); 
            scanf("%d",&n);  
            frontAdd(n); 
            break; 
        case 4: 
            printf("\nEnter element to delete in front : "); 
            scanf("%d",&n); 
            frontDel(n);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("\nExitted..");
            exit(9);
        default: 
            printf("\nPlease enter valid choice"); 
        }
    }
}

void rearAdd(int ele)
{
    if(t==max)
    {
        printf("Queue is full");
    }
    else
    {
        rear=(rear+1)%max;
        dque[rear]=ele;
        t=t-1;
        return;
    }
}

void rearDel(int ele)
{
    if(t==0)
    {
        printf("Queue is empty");
    }
    else
    {
        if(rear==-1)
            rear=max-1;
        printf("Deleted : %d",dque[rear]);
        rear=rear-1;
        t=t-1;
        return;
    }
}
void frontAdd(int ele)
{
    if(t==max)
    {
        printf("Queue is full");
    }
    else
    {
        if(front==0)
            front=max-1;
        else
            front-=1;
        dque[front]=ele;
        t=t+1;
        return;
    }
}
void frontDel(int ele)
{
    if(front==0)
        printf("Queue is Empty");
    else
    {   printf("Deleted : %d",dque[front]);
        front=(front+1)%max;
        t-=1;
        return;
    }
}
void display()
{
    if(t==0)
        printf("Queue Empty");
    else
    {
        x=front;
        for(i=1;i<-t;i++)
        {
            printf(" %d",dque[x]);
            x=(x+1)%max;
        }
    }
}