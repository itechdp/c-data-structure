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

struct Node* inOrderPredecssor(struct Node * root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    
    return root;
}
struct Node *deletion(struct Node* root, int key)
{
    struct Node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    

    if (key < root->data)
    {
        root->left = deletion(root->left , key);
    }
    else if(key > root->data)
    {
        root->right = deletion(root->right, key);
    }
    else
    {
        ipre = inOrderPredecssor(root);
        root->data = ipre->data;
        root->left = deletion(root , ipre->data);
    }
    return root;
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

    inorder(p1);
    printf("\n");
    deletion(p1,15);
    printf("\n");
    inorder(p1);
}