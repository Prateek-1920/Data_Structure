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
    return 1 + max(height(root->lchild), height(root->rchild));
}

void preorder(Nodeptr root)
{
    if (root)
    {
        printf("%d   ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
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

int main()
{
    Nodeptr root = NULL;

    int x;
    printf("Enter root of tree:");
    scanf("%d", &x);
    root = createtree(x);

    int h = height(root);
    int c = countnodes(root);
    printf("Height of tree is : %d", h);
    printf("nodes of tree is : %d", c);

    // printf("PRE ORDER: ");
    // preorder(root);
}