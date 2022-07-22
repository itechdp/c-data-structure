#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void paranThesis(struct stack *ptr, char exp[])
{
    int notPar = 0;
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(')
        {
            ptr->top++;
            ptr->arr[ptr->top] = '(';
        }

        else if (exp[i] == ')')
        {
            ptr->top--;
        }
    }

    if (ptr->top == -1)
    {
        printf("\nGiven expression has balenced paranthesis");
    }

    else
    {
        printf("\nGiven expression does not have balenced paranthesis");
    }
}

int main()
{
    struct stack *dp;
    dp->top = -1;
    dp->arr = (char *)malloc(dp->size * sizeof(char));
    char expr[1000];
    printf("Find whether the entered expression has balenced paranthesis or not!!!");
    printf("\nEnter you expression: ");
    gets(expr);

    paranThesis(dp, expr);
    return 0;
}
