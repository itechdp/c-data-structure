#include<stdio.h>
#include<stdlib.h>

struct stack{

    int size, top;
    int *arr;

};

int IsEmpty(struct stack * ptr)
{
    if(ptr->top == -1)
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
    if(ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *dp;
    dp->size = 6;
    dp->top = -1;
    dp->arr = (int *)malloc(dp->size * sizeof(int));
    dp->arr[0] = 10;
    dp->top++;

    if(IsEmpty(dp))
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is Full");
    }
}