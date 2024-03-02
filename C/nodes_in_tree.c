#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    struct node *rchild;
    int val;
};

typedef struct node *Nodeptr;

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
        temp->val = item;
        printf("Enter lchild of %d: ", item);
        scanf("%d", &x);
        temp->lchild = createtree(x);
        printf("Enter rchild of %d: ", item);
        scanf("%d", &x);
        temp->rchild = createtree(x);

        return temp;
    }

    return NULL;
}

int countnodes(Nodeptr root, int *opcount)
{

    if (root)
    {
        countnodes(root->lchild, opcount);
        countnodes(root->rchild, opcount);
        (*opcount)++;

        // printf("%d", root->val);
    }
}

int main()
{
    Nodeptr root = NULL;
    int x, opcount = 0;
    printf("Enter the value of root: ");
    scanf("%d", &x);
    root = createtree(x);

    int p = countnodes(root, &opcount);
    printf("Number of nodes = %d", opcount);
}
