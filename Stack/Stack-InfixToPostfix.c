#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
typedef struct Stack
{
    int top;
    int array[SIZE];
} Stack;

void initStack();
int isEmpty();
char peek();
char pop();
void push(char op);
int isOperand(char ch);
int precedence(char ch);
int infixToPostfix(char *);

Stack *stack;

int main()
{
    char exp[10];
    printf("Enter Infix Expression: "); 
    scanf("%s", &exp);
    initStack();
    infixToPostfix(exp);
}

void initStack()
{
    stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
}

int isEmpty()
{
    return stack->top == -1;
}

char peek()
{
    return stack->array[stack->top];
}

char pop()
{
    if (!isEmpty(stack))
    {
        return stack->array[stack->top--];
    }
    return '$';
}

void push(char op)
{
    stack->array[++stack->top] = op;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z' ||
            ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

int infixToPostfix(char *exp)
{
    int i, k;
    if (!stack)
        return -1;

    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        else if (exp[i] == '(')
            push(exp[i]);

        else if (exp[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
                exp[++k] = pop();
            if (!isEmpty() && peek() != '(')
                return -1;
            else
                pop();
        }

        else
        {
            while (!isEmpty() && precedence(exp[i]) <= precedence(peek()))
                exp[++k] = pop();
            push(exp[i]);
        }
    }

    while (!isEmpty())
        exp[++k] = pop();

    exp[++k] = '\0';
    printf("%s", exp);
}