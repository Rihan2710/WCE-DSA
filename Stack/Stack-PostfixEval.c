
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
typedef struct Stack
{
    int top;
    int array[SIZE];
} Stack;

void initStack();
void push(int value);
int pop();
void display();
void eval(char *);

Stack *stack;

int main()
{
    char exp[] = "29+756-*";
    eval(exp);
}

void initStack()
{
    stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
}

void push(int value)
{

    if (stack->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = value;
}

int pop()
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    int temp = stack->array[stack->top];
    stack->top--;
    return temp;
}

void display()
{

    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

void eval(char *exp)
{
    initStack();
    int i = 0;

    for (i = 0; exp[i]; ++i)
    {

        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(exp[i] - '0');
        }
        else
        {
            int op1, op2, val;
            op1 = pop();
            op2 = pop();
            switch (exp[i])
            {
            case '+':
                val = op2 + op1;
                break;
            case '-':
                val = op2 - op1;
                break;
            case '*':
                val = op2 * op1;
                break;
            case '/':
                val = op2 / op1;
                break;
            case '^':
                val = op2 ^ op1;
                break;
            }
            push(val);
        }
    }
    display();
}
