#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;

struct node
{
    int data;
    Nodeptr lchild;
    Nodeptr rchild;
};

Nodeptr getnode()
{
    return (Nodeptr)malloc(sizeof(struct node));
}

Nodeptr createBST(Nodeptr root, int item)
{
    if (root == NULL)
    {
        root = getnode();
        root->data = item;
        root->lchild = root->rchild = NULL;
        return root;
    }
    else if (item < root->data)
    {
        root->lchild = createBST(root->lchild, item);
    }
    else if (item > root->data)
    {
        root->rchild = createBST(root->rchild, item);
    }
    else
    {
        printf("Duplicates not allowed");
    }
}

int countnodes(Nodeptr root)
{
    static int count = 0;

    if (root != NULL)
    {
        countnodes(root->rchild);
        count++;
        countnodes(root->lchild);
    }
    return count;
}

int countleaf(Nodeptr root)
{
    static int countl = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->lchild == NULL && root->rchild == NULL)
    {
        return 1;
    }
    else
    {
        return countleaf(root->lchild) + countleaf(root->rchild);
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int height(Nodeptr root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->lchild == NULL && root->rchild == NULL)
    {
        return 1;
    }
    else
    {
        return 1 + max(height(root->lchild), height(root->rchild));
    }
}

void inorder(Nodeptr root)
{
    if (root)
    {
        inorder(root->lchild);
        printf("%d  ", root->data);
        inorder(root->rchild);
    }
}

int search(Nodeptr root, int ele)
{
    while (root)
    {
        if (root->data == ele)
        {
            return 1;
        }
        if (ele < root->data)
        {
            root = root->lchild;
        }
        else
        {
            root = root->rchild;
        }
    }
    return 0;
}

int maxele(Nodeptr root)
{
    if (root == NULL)
    {
        printf("Tree empty: ");
        return 0;
    }
    while (root->rchild != NULL)
    {
        root = root->rchild;
    }
    return root->data;
}

int minele(Nodeptr root)
{
    if (root == NULL)
    {
        printf("Tree empty: ");
        return 0;
    }
    while (root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root->data;
}

void insert(Nodeptr root, int item)
{
    Nodeptr temp = getnode();
    temp->data = item;
    temp->lchild = temp->rchild = NULL;

    if (root == NULL)
    {
        root = temp;
        return;
    }

    Nodeptr parent, current;
    current = root;

    while (current)
    {
        parent = current;
        if (item == current->data)
        {
            printf("Duplicates not allowed.");
            return;
        }
        else if (item > current->data)
        {
            current = current->rchild;
        }
        else
        {
            current = current->lchild;
        }
    }
    if (item < parent->data)
    {
        parent->lchild = temp;
    }
    else if (item > parent->data)
    {
        parent->rchild = temp;
    }
}

int main()
{
    Nodeptr root = NULL;
    int x;
    while (x != -1)
    {
        printf("Enter data: ");
        scanf("%d", &x);

        if (x != -1)
            root = createBST(root, x);
    }

    printf("INORDER: ");
    inorder(root);

    int c = countnodes(root);
    printf("Number of nodes: %d\n ", c);

    int l = countleaf(root);
    printf("Number of leaf nodes: %d\n ", l);

    int h = height(root);
    printf("height of tree: %d\n ", h);

    int max = maxele(root);
    printf("largest element of tree is: %d\n", max);

    int min = minele(root);
    printf("Smallest element of tree is: %d\n", min);

    // printf("element to search: ");
    // int e;
    // scanf("%d", &e);

    // int s = search(root, e);
    // if (s != 0)
    // {
    //     printf("Element exists in the tree .");
    // }
    // else
    // {
    //     printf("Element not found.");
    // }

    printf("Enter element to insert: ");
    int ie;
    scanf("%d", &ie);
    insert(root, ie);
    inorder(root);
}
