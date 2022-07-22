#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *head)
{
    struct Node *p = head;
    do
    {
        printf("Element:%d\n", p->data);
        p = p->next;
    } while (p != head);
}

struct Node *DeleteAtBeginning(struct Node *head)
{
    struct Node *p = head;
    struct Node *ptr = head->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = head->next;
    free(p);
    head = ptr;
    return head;
}

struct Node *DeleteInBetween(struct Node *head, int index)
{
    int i = 0;
    struct Node *ptr = head;
    struct Node *qtr = head->next;
    while (i != index - 1)
    {
        ptr = ptr->next;
        qtr = qtr->next;
        i++;
    }
    ptr->next = qtr->next;
    free(qtr);
    return head;
}

struct Node *DeleteAtEnding(struct Node *head)
{
    struct Node *ptr = head->next;
    struct Node *qtr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
        qtr = qtr->next;
    }

    qtr->next = ptr->next;
    free(ptr);
    return head;
}

struct Node *DeleteAfterNode(struct Node *head,struct Node *prevnode)
{
    struct Node *ptr = prevnode , *qtr = prevnode->next;
    ptr->next = qtr->next;
    free(qtr);
    return head;
    
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = head;

    head = DeleteAfterNode(head,fourth);
    Traversal(head);
}