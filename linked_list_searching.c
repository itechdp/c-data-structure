#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    int i = 0, flag = 1;

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

    int ele;

    printf("Enter the element you want to search: ");
    scanf("%d", &ele);

    struct Node *p = head;

    while (p != NULL)
    {
        if (p->data == ele)
        {
            printf("%d is found on index %d", p->data, i);
            flag = 1;
            break;
        }

        else
        {
            flag = 0;
        }
        p = p->next;
        i++;
    }

    if (flag == 0)
        printf("\nElement Not found: %d", ele);
}