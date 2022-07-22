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
        printf("Element: %d\n", p->data);
        p = p->next;
    } while (p != head);
}

void SearchingCLL(struct Node *head, int element)
{
    int i = 1, flag = 0;
    struct Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
        if (ptr->data == element)
        {
            printf("Element %d found of index %d", element, i);
            flag = 0;
            break;
        }
        else
        {
            flag = 1;
        }

        i++;
    }

    if (flag == 1)
    {
        printf("\nElement is not found.");
    }
 
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
    fourth->next = head;
    SearchingCLL(head,30);
   

    return 0;
}