#include<stdio.h>
#include<stdlib.h>

// Constructing a node, where we are goint to store integer type of data and using node pointer to point the next node.
struct Node
{
    int data;
    struct Node * Next;
};


int main()
{
    // Declaring the nodes.
    struct Node * head;
    struct Node * second;
    struct Node * third;

    // Inalize the nodes with dynamic memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node* )malloc(sizeof(struct Node));

    // Stroring data 10 in node head, and storing the address of second node using Next.
    head->data = 10;
    head->Next  = second;

    second->data = 20;
    second->Next = third;

    third->data = 30;
    third->Next = NULL;

    // Make a new ptr node pointer to and making that ptr = hear or starting point of the linked list and using while loop iterrating the ptr till NULL 
    struct Node * ptr;
    ptr = head;

    // Trevarsal of node data.
    while (ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->Next;
    }
    
    return 0;


}