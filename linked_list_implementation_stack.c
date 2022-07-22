#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct stack
{
    int size;
    int top;
    int *arr;
};

struct stack *Push(struct stack *dp, struct Node *head)
{
    struct Node *ptr = head;
    struct stack *dtr = dp;
    while (ptr != NULL)
    {
        dtr->top++;
        dtr->arr[dtr->top] = ptr->data;
        printf("Pushed data: %d\n", dtr->arr[dtr->top]);
        ptr = ptr->next;
    }
    
    return dp;
}

struct stack *pop(struct stack *dp)
{
    if (dp->top == -1)
    {
        printf("Cannot popped underflow condition.");
    }
    else
    {
        int data;
        data = dp->arr[dp->top-1];
        printf("\nPopped Top most data from the stack: %d",data);
        dp->top--;
        return dp;
    }
}

void peek(struct stack *dp)
{
    printf("Top Most element of the stack: %d",dp->arr[dp->top-1]);
}

void stackTop(struct stack *dp)
{
    printf("\nStack Top Most element: %d",dp->arr[dp->top]);
}

void stackBottom(struct stack *dp)
{
    printf("\nBottom element of the stack: %d",dp->arr[0]);
}

void Traversal(struct stack *dp)
{
    int topMost = dp->top;
    int i = 1;
    dp->top = 0;
    while (dp->top != topMost + 1)
    {
        printf("Stack Element: %d Position:%d\n", dp->arr[dp->top++], i++);
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *top;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    top = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    struct stack *dp;
    dp->top = -1;
    dp->size = 10;
    dp->arr = (int *)malloc(dp->size * sizeof(int));
    Push(dp, head);
    Traversal(dp);
    peek(dp);
    pop(dp);
    stackTop(dp);
    stackBottom(dp);
    return 0;
}
