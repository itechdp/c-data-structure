#include <stdlib.h>
#include <malloc.h>

struct Node
{

    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n;                                 // Declaring the node as refrenced to structure;
    n = (struct Node *)malloc(sizeof(struct Node)); // initialize the node in heap memory
    n->data = data;                                 // giving the data of the node
    n->left = NULL;                                 // considering left child node of n as null
    n->right = NULL;                                // considering right child node of n as null
    return n;                                       // returning the node
}

int main()
{
    struct Node *p = createNode(0);  // creating a nodes and calling a function createNode
    struct Node *p1 = createNode(1); // creating a nodes and calling a function createNode
    struct Node *p2 = createNode(2); // creating a nodes and calling a function createNode
    struct Node *p3 = createNode(3); // creating a nodes and calling a function createNode
    struct Node *p4 = createNode(4); // creating a nodes and calling a function createNode
    struct Node *p5 = createNode(5); // creating a nodes and calling a function createNode

    // Linking all the both the ends of the node with other node as per the tree structure.
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = NULL;

    p2->left = p4;
    p2->right = p5;

    p3->left = NULL;
    p3->right = NULL;

    p4->left = NULL;
    p4->right = NULL;

    p5->left = NULL;
    p5->right = NULL;

    return 0;
}