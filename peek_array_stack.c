#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int IsEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peekTopMost(struct stack *ptr)
{

    int arrINd = ptr->top;
    if (arrINd < 0)
    {
        printf("Cannot peek underflow condition.");
        return -1;
    }
    else
    {
        return ptr->arr[arrINd];
    }
}

void Traversal(struct stack *ptr)
{
    int topMost = ptr->top;
    ptr->top = 0;
    int i = 1;
    while (ptr->top != topMost+1)
    {
       printf("\nTraversal in the stack: \nElement->%d \nPosition->%d\n",ptr->arr[ptr->top++],i);
        i++;
    }
}

void pushStack(struct stack *ptr, int data)
{
    ptr->top++;
    ptr->arr[ptr->top] = data;
}

int main()
{

    struct stack *dp;
    dp->size = 10;
    dp->top = -1;
    dp->arr = (int *)malloc(dp->size * sizeof(int));

    if (IsFull(dp))
    {
        printf("Stack is full overflow condition.");
    }
    else
    {
        pushStack(dp, 10);
        pushStack(dp, 20);
        pushStack(dp, 30);
    }


    if (IsEmpty(dp))
    {
        printf("Cannot peek the value underflow condtion.");
    }
    else
    {
        printf("\nThe elemnts in the stack: \nElement->%d \nPosition->Top Most\n", peekTopMost(dp));
    }

    Traversal(dp);
    

    return 0;
}