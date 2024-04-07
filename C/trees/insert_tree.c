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

void insertnode(Nodeptr root, char direction[], int item)
{
    Nodeptr temp, curr, parent;
    temp = getnode();
    temp->data = item;

    parent = NULL;
    curr = root;

    int i = 0;

    while (curr && direction[i])
    {
        parent = curr;
        if (direction[i] == 'L' || direction[i] == 'l')
        {
            curr = curr->lchild;
        }
        else
        {
            curr = curr->rchild;
        }
        i++;
    }
    if (curr != NULL || direction[i] != '\0')
    {
        printf("not possible");
        return;
    }
    if (direction[i - 1] == 'L' || direction[i - 1] == 'l')
        parent->lchild = temp;
    else
        parent->rchild = temp;
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

int main()
{
    int x;
    Nodeptr root = getnode();
    root->data = 10;
    root->lchild = root->rchild = NULL;

    insertnode(root, "L", 5);
    insertnode(root, "R", 15);

    printf("INRODER");
    inorder(root);
}
