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
    return ((Nodeptr)malloc(sizeof(struct node)));
}

Nodeptr createtree(int item)
{
    int x;
    if (item != -1)
    {
        Nodeptr temp = getnode();
        temp->data = item;
        printf("Enter left child of %d: ", item);
        scanf("%d", &x);
        temp->lchild = createtree(x);
        printf("Enter right child of %d: ", item);
        scanf("%d", &x);
        temp->rchild = createtree(x);

        return temp;
    }

    return NULL;
}

int countnodes(Nodeptr root)
{
    if (root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + countnodes(root->lchild) + countnodes(root->rchild);
        }
    }
}

int countleaf(Nodeptr root)
{
    if (root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->lchild == NULL && root->rchild == NULL)
        {
            return 1;
        }
        else
        {
            return countleaf(root->lchild) + countleaf(root->rchild);
        }
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
    if (root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->lchild == NULL && root->rchild == NULL)
        {
            return 1;
        }
        else
        {
            return 1 + max(height(root->lchild), height(root->rchild));
        }
    }
}

int search(Nodeptr root, int item)
{
    static int i;
    if (root)
    {
        if (root->data == item)
        {
            i++;
        }
        if (i == 0)
        {
            search(root->lchild, item);
        }
        if (i == 0)
        {
            search(root->rchild, item);
        }
    }
    return i;
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

int main()
{
    Nodeptr root = NULL;
    int x;
    printf("Enter value of root: ");
    scanf("%d", &x);

    root = createtree(x);

    printf("INORDER: ");
    inorder(root);

    printf("Number of nodes = %d\n", countnodes(root));
    printf("Number of LEAF nodes = %d", countleaf(root));
    printf("height = %d", height(root));

    int s;
    printf("Enter element to search: ");
    scanf("%d", &s);
    int r = search(root, s);

    if (r == 0)
    {
        printf("not found");
    }
    else
    {
        printf("found");
    }
}