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

Nodeptr creattree(int item)
{
    int x;
    if (item != -1)
    {
        Nodeptr temp = getnode();
        temp->data = item;
        printf("Enter left to %d: ",item);
        scanf("%d", &x);
        temp->lchild = creattree(x);
        printf("Enter right to %d: ",item);
        scanf("%d", &x);
        temp->rchild = creattree(x);

        return temp;
    }
    return NULL;
}

int search(Nodeptr root, int e)
{
    static int i;
    if (root)
    {
        if (root->data == e)
        {
            i++;
            return i;
        }

        
        if (i == 0)
        {
            search(root->lchild, e);
        }
        if (i == 0)
        {
            search(root->rchild, e);
        }
    }
    return i;
}

int main()
{
    Nodeptr root = NULL;
    int item;
    printf("Enter root of the tree: ");
    scanf("%d", &item);
    root = creattree(item);

    int ele;
    printf("Enter element to search: ");
    scanf("%d", &ele);

    int result = search(root, ele);

    if (result > 0)
    {
        printf("Element %d found in the tree.\n", ele);
    }
    else
    {
        printf("Element %d not found in the tree.\n", ele);
    }

    return 0;
}