#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void TraversalFromNext(struct Node *head)
{
    struct Node *p = head;
    while (p!=NULL)
    {
        printf("Element: %d\n",p->data);
        p = p->next;
    }
    
}

void TraversalFromPrev(struct Node *lastNode)
{
    struct Node *ptr = lastNode;
    while (ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->prev;
    }
    
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *Second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head->next = Second;
    head->prev = NULL;
    head->data = 10;

    Second->next = third;
    Second->prev = head;
    Second->data = 20;

    third->next = fourth;
    third->prev = Second;
    third->data = 30;

    fourth->next = fifth;
    fourth->prev = third;
    fourth->data = 40;

    fifth->next = NULL;
    fifth->prev = fourth; 
    fifth->data = 50;
    TraversalFromNext(head);
    TraversalFromPrev(fifth);
}