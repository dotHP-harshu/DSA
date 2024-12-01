#include <stdio.h>
#include <stdlib.h>
#define MAX 5
// define the structure of a stack
struct Stack
{
    int top;
    int arr[MAX];
};
// initialize the stack mean give -1 to top
void initializeStack(struct Stack *stack)
{
    stack->top = -1;
}
// check if stack is overflow or full
int isFull(struct Stack *stack)
{
    return stack->top == MAX - 1;
}
// check if stack is underflow or empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
// push a value into the stack
void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack is full.\n");
        return;
    }

    stack->top = stack->top + 1;

    stack->arr[stack->top] = value;
    printf("%d has pushed into the stack.\n", value);
}
// pop the value from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty, can't pop element.\n");
        return -1;
    }
    int popedElement = stack->arr[stack->top];
    stack->top = stack->top - 1;
    return popedElement;
}
// retrieve the peek or top value
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->arr[stack->top];
}
// print the stack
void printStack(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty, can't print element.\n");
        return;
    }
    printf("Stack elements:");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d  ", stack->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack harsh; // make a new stack named harsh

    initializeStack(&harsh);                       // initialize the harsh stack
    push(&harsh, 10);                              // push 10 into the harsh stack
    push(&harsh, 20);                              // push 20 into the harsh stack
    push(&harsh, 30);                              // push 30 into the harsh stack
    printf("Poped : %d\n", pop(&harsh));           // poped
    printf("Poped : %d\n", pop(&harsh));           // poped
    printf("Peek element is %d.\n", peek(&harsh)); // get the top value

    push(&harsh, 40);                              // push 40
    push(&harsh, 50);                              // push 50
    printf("Peek element is %d.\n", peek(&harsh)); // get the top value
    printStack(&harsh);                            // print the stack
    return 0;
}