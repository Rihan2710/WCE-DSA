// Stack-DecimalToBinary
#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef struct Stack
{
    int array[SIZE];
    int top;
} Stack;

void initStack();
void push(int value);
int pop();

Stack *stack;

int main()
{
    stack = (Stack *)malloc(sizeof(Stack));
    int decimal;
    printf("Enter Decimal: ");
    scanf("%d", &decimal);

    initStack();

    while (decimal != 0)
    {
        int rem = decimal % 2;
        push(rem);
        decimal /= 2;
    }

    printf("Binary: ");
    while (stack->top != -1)
    {
        printf("%d", pop());
    }
}

void initStack()
{
    stack->top = -1;
}

void push(int value)
{
    if (stack->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack->array[++stack->top] = value;
}

int pop()
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack->array[stack->top--];
}
