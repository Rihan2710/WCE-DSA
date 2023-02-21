#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void create();
void enqueue(int);
void dequeue(int);
void display();

int cque[MAX];
int front,rear;
void main()
{
    int n,choice;
    printf("\nPress - 1 to Insert element in Circular Queue "); 
    printf("\nPress - 2 to Delete element in Circular Queue "); 
    printf("\nPress - 3 to Display Circular Queue "); 
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
        else{
            if(rear==MAX-1)
                rear=0;
            else
                rear+=1;
        }
      cque[rear]=ele;
      return;  
    }
}
void dequeue(int ele)
{   
    int d;
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
    }
    if(front==MAX-1)
        front=0;
    else{
        front+=1;
        return;
    }

}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Queue Empty");
        return;
    }
    else
    {
       for(i=front;i<=rear;i++)
       {
            printf(" %d",cque[i]);
            
       }
    }
    return;
}