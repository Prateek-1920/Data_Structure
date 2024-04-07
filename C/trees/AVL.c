#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b ? a : b);
}

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createnode(int key)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->left = newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int getheight(struct node *Node)
{
    if (Node == NULL)
    {
        return 0;
    }
    return Node->height;
}

int getbalance(struct node *Node)
{
    if (Node == NULL)
    {
        return 0;
    }
    return getheight(Node->left) - getheight(Node->right);
}

void updateheight(struct node *Node)
{
    if (Node != NULL)
    {
        Node->height = 1 + max(getheight(Node->left), getheight(Node->right));
    }
}

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *z = x->right;

    x->right = y;
    y->left = z;

    updateheight(y);
    updateheight(x);

    return x;
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *z = y->left;

    y->left = x;
    x->right = z;

    updateheight(x);
    updateheight(y);

    return y;
}

struct node *insertnode(struct node *root, int key)
{
    if (root == NULL)
    {
        return createnode(key);
    }

    if (key < root->key)
    {
        root->left = insertnode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insertnode(root->right, key);
    }
    else
        return root;

    updateheight(root);
    int balance = getbalance(root);

    if (balance > 1 && key < root->left->key)
    {
        return rightrotate(root); // LL rotation
    }
    if (balance < 1 && key > root->left->key)
    {
        return leftrotate(root); // RR rotation
    }
    if (balance > 1 && key > root->left->key)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < 1 && key < root->left->key)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main()
{
    int r, x;
    struct node *root = NULL;

    printf("Enter root: ");
    scanf("%d", &r);
    root = createnode(r);
    while (1)
    {
        printf("Enter element: ");
        scanf("%d", &x);
        if (x == -1)
        {
            break;
        }
        root = insertnode(root, x);
    }

    printf("\nInorder traversal : ");
    inorderTraversal(root);
}