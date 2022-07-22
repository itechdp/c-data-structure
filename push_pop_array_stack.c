#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void pushStack(struct stack *ptr, int data)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("\nCannot push overflow condition.");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
        printf("\nPushed Data: %d", data);
    }
}

void popStack(struct stack *ptr)
{
    int value;
    if (ptr->top == -1)
    {
        printf("\nCannot pop underflow condition.");
    }
    else
    {
        value = ptr->arr[ptr->top];
        ptr->top--;
        printf("\nPopped value :%d", value);
    }
}

int TraversalStack(struct stack *ptr , int i )
{
    int arrInd = ptr->top - i +1;
    int data;
    if (arrInd<0)
    {
        printf("Cannot peek the stack is empty");
        return -1;
    }
    else
    {
        data = ptr->arr[arrInd];
        return data;
    }

}

int main()
{
    struct stack *dp;
    dp->size = 10;
    dp->top = -1;
    dp->arr = (int *)malloc(dp->size * sizeof(int));
    pushStack(dp, 2);
    pushStack(dp,5);
    pushStack(dp,1000);
    popStack(dp);
    popStack(dp);

  
    return 0;
}
