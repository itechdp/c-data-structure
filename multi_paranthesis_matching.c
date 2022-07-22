#include <Stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{

    int size;
    int top;
    char *arr;
};

int match(char push, char pop)
{
    if (push == '(' && pop == ')' && push == '{' && pop == '}' && push == '[' && pop == ']')
    {
        return 1;
    }
    else
        return 0;
}

void multiPara(struct stack *ptr, char expr[])
{
    char popped, pushed;
    int matched;
    for (int i = 0; i <= strlen(expr); i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            ptr->top++;
            ptr->arr[ptr->top] = expr[i];
        
        }

        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            popped = expr[i];
            printf("%c", popped);
            ptr->top--;
        }
        matched = match(expr[i], popped);
    }
    if (matched == 1)
    {
        if (ptr->top == -1)
        {
            printf("Paranthesis are balenced");
        }
    }

    else if (matched == 0)
    {
        if (ptr->top > -1)
        {
            printf("paranthesis are not balenced");
        }
    }
}

int main(int argc, char const *argv[])
{
    struct stack *dp;
    dp->size = 100;
    dp->top = -1;
    dp->arr = (char *)malloc(dp->size * sizeof(char));
    char exp[100];
    printf("Enter the expression to check whether that expression has balenced paranthesis or not!!!\nEnter your expression:");
    gets(exp);
    multiPara(dp, exp);
    return 0;
}
