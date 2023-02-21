#include<stdio.h>
#include<stdlib.h>

int stack[5];
int top=-1;
void push();
void pop();
void display();

int main()
{
    int ch;
    do
    {
        printf("\n 1.Push");
        printf("\n 2.Pop");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n Wrong choice");
        }
        
    }
    while(ch!=0);
    return 0;    
}
void push()
{
    int num;
    if(top==4)
        printf("\n Stack Overflow");
    else
    {
        printf("\n Enter number : ");
        scanf("\n %d",&num);
        top=top+1;
        stack[top]=num;
    }
}
void pop()
{
    int num;
    if(top==-1)
        printf("\n Stack is empty");
    else
    {
        num=stack[top];
        top=top-1;
        printf("\n Popped");
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("\n %d",stack[i]);
        }
    }
}