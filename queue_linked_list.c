#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr)
{
    printf("\nPrinting the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n==NULL)
    {
        printf("Queue is full");
    }
    
    else
    {
        n->data = data;
        n->next = NULL;
        if (f==NULL)
        {
            f=r=n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    printf("%d added to the queue", data);
    }

}

int dequeue(struct Node*ptr)
{
    struct Node *p = f;
    int data = -1;
    if (f==NULL)
    {
        printf("Queue is full");
    }
    else
    {
        f = f->next;
        data = p->data;
        printf("%d deleted to the queue",data);
        free(p);
    }
    return data;
    
}



int main()
{
    enqueue(10);
    linkedListTraversal(f);
}