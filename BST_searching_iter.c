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

int Isbst(struct Node *root)
{
    struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!Isbst(root->left))
        {
            return 0;
        }

        if (prev != NULL && prev->data <= root->data)
        {
            return 0;
        }

        prev = root;
        return Isbst(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct Node *searchiter(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
            
        }
        else
        {
            root = root->right;
        }
    }

    return NULL;
}

int main()
{
    struct Node *p1 = createNode(20);
    struct Node *p2 = createNode(17);
    struct Node *p3 = createNode(22);
    struct Node *p4 = createNode(15);
    struct Node *p5 = createNode(18);
    struct Node *p6 = createNode(21);
    struct Node *p7 = createNode(25);

    p1->left = p2;
    p1->right = p3;

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

    struct Node *n = searchiter(p1, 15);

    if (n != NULL)
    {
        printf("Element found: %d", n->data);
    }
    else
    {
        printf("Element not found");
    }
}