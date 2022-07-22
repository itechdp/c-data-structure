// Delete node from the first
// Delete node in between
// Delete node from the last
// Delete after node
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("\nElement: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *DeleteAtFirst(struct Node *head)
{
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;
}

struct Node *DeleteNodeInBetween(struct Node *head, int index)
{
    struct Node *p = head, *q;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node *DeleteAtEnd(struct Node *head)
{
    struct Node *p = head, *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

struct Node *DeleteAfterNode(struct Node *head, struct Node *prevnode)
{
    struct Node *p = head, *q = head->next;
    while (p != prevnode)
    {
        q = q->next;
        p = p->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main()
{

    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    // printf("Delete At First");
    // first = DeleteAtFirst(first);
    // Traversal(first);

    // printf("Delete in between");
    // first = DeleteNodeInBetween(first, 2);
    // Traversal(first);

    // printf("Delete in between");
    // first = DeleteAtEnd(first);
    // Traversal(first);

    // printf("Delete After Node");
    // first = DeleteAfterNode(first, second);
    // Traversal(first);

    return 0;
}