#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void create();
void enqueue(int);
void dequeue(int);
void display();

int que[MAX];
int front,rear;
void main()
{
    int n,choice;
    printf("\nPress - 1 to Insert element in Queue "); 
    printf("\nPress - 2 to Delete element in Queue "); 
    printf("\nPress - 3 to Display Queue "); 
    printf("\nPress - 4 to Exit ");  
    create();
    while (1)
    {
        printf("\nEnter your choice :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: 
            printf("\nEnter element to insert : "); 
            scanf("%d",&n); 
            enqueue(n); 
            break; 
        case 2: 
            printf("\nEnter element to delete : "); 
            scanf("%d",&n); 
            dequeue(n); 
            break; 
        case 3: 
            display(); 
            break; 
        case 4: 
            printf("\nExitted Successfuly");
            exit(9); 
        default: 
            printf("\nPlease enter valid choice"); 
        }
    }
}
void create()
{
    front = -1;
    rear = -1;
}
void enqueue(int ele)
{
    if(front==0 && rear==MAX-1)
    {
        printf("Overflow");
        return;
    }
    else{
        if(front==-1 && rear==-1)
            front = rear =0;
        else
        {
           rear+=1;
           que[rear]=ele;
        }
      return;  
    }
}
void dequeue(int ele)
{   
    if(front==-1 && rear==-1)
    {
        printf("Queue Empty");
        return;
    }
    else
    {
        if(front==rear)
        {
            front = rear =-1;
        }
        else
        {
            front+=1;
            printf("Deleted");
        }
    return;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue Empty");
        return;
    }
    else
    {
       for(int i=front;i<=rear;i++)
       {
            printf(" %d",que[i]);     
       }
    }
}


