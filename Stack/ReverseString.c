#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
typedef struct Stack
{
    char array[SIZE];
    int top;
} Stack;

void initStack();
void push(char value);
char pop();

Stack *stack;

int main()
{
    char string[] = "Rihan Nardekar";

    printf("String: %s\n", string);

    initStack();
    push('h');

    for (int i = 0; i < strlen(string); i++)
    {
        push(string[i]);
    }

    printf("Reverse String: ");
    for (int i = 0; i < strlen(string); i++)
    {
        printf("%c", pop());
    }
}

void initStack()
{
    stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
}

void push(char value)
{

    if (stack->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = value;
}

char pop()
{

    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    return stack->array[stack->top--];
}