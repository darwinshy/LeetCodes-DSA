#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top_pointer;
    unsigned capacity;
    int *data;
};

// Create a Stack Variable Function
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top_pointer = -1;
    stack->data = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
};

void push(struct Stack *stack, int newItem)
{
    if (isStackFull)
        return;

    stack->data[stack->top_pointer++] = newItem;
}

void pop(struct Stack *stack)
{
    if (isStackEmpty(stack))
        return;
    stack->top_pointer--;
}

int peek(struct Stack *stack)
{
    if (isStackEmpty(stack))
        return -1;
    return stack->data[stack->top_pointer];
}

int isStackFull(struct Stack *stack)
{
    return stack->top_pointer == (stack->capacity - 1);
}

int isStackEmpty(struct Stack *stack)
{
    return stack->top_pointer == -1;
}
