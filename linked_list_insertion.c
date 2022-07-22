// Adding node at starting of the list
// Adding node in between
// Adding node in the last
// Adding node after given node address;

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr)
{

    // Trevarsal of node data.
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *InsertAtBeginning(struct Node *head, struct Node *ptr)
{
    // struct Node * ptr;
    ptr->data = 40;
    ptr->next = head;
    ptr = head;
    return head;
}

struct Node *InsertAtIndex(struct Node *head, struct Node *ptr, int index)
{
    int i = 0;
    struct Node *p;
    p = head;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *InsertAtEnd(struct Node *head, struct Node *ptr)
{
    struct Node *p;
    ptr->data = 40;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    ptr->next = NULL;
    p->next = ptr;

    return head;
}

struct Node *InsertAfterNode(struct Node *prevnode, struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    // Uncomment below lines as per the implimantation

    // Traversal(head);

    // printf("Insert At Beginning\n");
    // head = InsertAtBeginning(head, fourth);
    // Traversal(head);

    // printf("\nInsert At Index\n");
    // head = InsertAtIndex(head, fourth, 2);
    // Traversal(head);

    // printf("\nInsert At End\n");
    // head = InsertAtEnd(head,fourth);
    // Traversal(head);

    // printf("Insert After Node");
    // head = InsertAfterNode(second, head, 50);
    // Traversal(head);

    return 0;
}