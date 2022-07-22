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

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct Node *p = createNode(20);
    struct Node *p2 = createNode(15);
    struct Node *p3 = createNode(25);
    struct Node *p4 = createNode(12);
    struct Node *p5 = createNode(16);
    struct Node *p6 = createNode(23);
    struct Node *p7 = createNode(27);

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

    printf("\nInorder Traversal:\n");
    inorder(p);
    if (isBST(p))
    {
        printf("\nThe given tree is binary search tree");
    }
    else
    {
        printf("\nThe given tree is not a binary search tree");
    }

    return 0;
}
