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

void inorder(Nodeptr root)
{
    if (root)
    {
        inorder(root->lchild);
        printf("%d  ", root->data);
        inorder(root->rchild);
    }
}

int equal(Nodeptr root1, Nodeptr root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if (root1 != NULL && root2 != NULL && (root1->data == root2->data))
    {
        return equal(root1->lchild, root2->lchild) && equal(root1->rchild, root2->rchild);
    }
    return 0;
}

int main()
{
    Nodeptr tree1 = NULL;
    Nodeptr tree2 = NULL;
    printf("Enter root of tree1: ");
    int n1;
    scanf("%d", &n1);
    tree1 = createtree(n1);
    inorder(tree1);

    printf("Enter root of tree2: ");
    int n2;
    scanf("%d", &n2);
    tree2 = createtree(n2);
    inorder(tree2);

    int check = equal(tree1, tree2);
    if (check == 1)
    {
        printf("EQUAL");
    }
    else
    {
        printf("NOPE");
    }
}