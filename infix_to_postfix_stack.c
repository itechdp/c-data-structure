#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

int pushStack(struct stack *ptr, int data)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("\nCannot push overflow condition.");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
        // printf("\nPushed Data: %d", data);
    }
}

int popStack(struct stack *ptr)
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
        // printf("\nPopped value :%d", value);
        return value;
    }
}

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

int isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
        return 0;
}

int prec(char pr)
{
    if (pr == '*' || pr == '/')
        return 3;
    else if (pr == '+' || pr == '-')
        return 2;
    else
        return 0;
}

char *infixtopostfix(char *infix)
{
    int i = 0, j = 0;
    struct stack *dp = (struct stack *)malloc(sizeof(struct stack));
    dp->top = -1;
    dp->size = 100;
    dp->arr = (char *)malloc(dp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (prec(infix[i]) > prec(dp->arr[dp->top]))
            {
                pushStack(dp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = popStack(dp);
                j++;
            }
        }
    }

    while (!IsEmpty(dp))
    {
        postfix[j] = popStack(dp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int peekTopMost(struct stack *ptr)
{

    int arrINd = ptr->top;
    if (arrINd < 0)
    {
        // printf("Cannot peek underflow condition.");
        return -1;
    }
    else
    {
        return ptr->arr[arrINd];
    }
}

int main()
{
    char *infix = "a+b";
    printf("Postfix: %s", infixtopostfix(infix));

    return 0;
}
