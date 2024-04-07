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

void inorder(Nodeptr root)
{
    if (root)
    {
        inorder(root->lchild);
        printf("%d   ", root->data);
        inorder(root->rchild);
    }
}

void postorder(Nodeptr root)
{
    if (root)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d   ", root->data);
    }
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

int main()
{
    Nodeptr root = NULL;
    int item;

    printf("Enter root value of tree: ");
    scanf("%d", &item);

    root = createtree(item);

    printf("INORDER: ");
    inorder(root);
    printf("POST ORDER: ");
    postorder(root);
    printf("PRE ORDER: ");
    preorder(root);
}