#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root)
{

    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *p = createNode(1);
    struct Node *p2 = createNode(2);
    struct Node *p3 = createNode(3);
    struct Node *p4 = createNode(4);
    struct Node *p5 = createNode(5);
    struct Node *p6 = createNode(6);
    struct Node *p7 = createNode(7);

    p->left = p2;
    p->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = p6;
    p3->right = p7;

    p4->left = NULL;
    p4->right = NULL;

    p5->left = NULL;
    p5->right = NULL;

    p6->left = NULL;
    p6->right = NULL;

    p7->left = NULL;
    p7->right = NULL;

    printf("Preorder Traversal:\n");
    preorder(p);
    printf("\nInorder Traversal:\n");
    inorder(p);
    printf("\nPostorder Traversal:\n");
    postorder(p);

    return 0;
}