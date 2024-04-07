#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node *Nodeptr;

struct node
{
    char data;
    Nodeptr lchild;
    Nodeptr rchild;
};

Nodeptr getnode()
{
    return (Nodeptr)malloc(sizeof(struct node));
}

Nodeptr createtree(char e)
{
    Nodeptr temp = getnode();
    temp->data = e;
    temp->rchild = temp->lchild = NULL;
    return temp;
}

int isAlphanumeric(char c)
{
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

Nodeptr expression()
{
    char exp[100];
    printf("Enter expression: ");
    scanf("%99s", exp);

    Nodeptr stack[100];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char current = exp[i];

        if (isAlphanumeric(current))
        {
            stack[++top] = createtree(current);
        }
        else
        {
            Nodeptr temp = createtree(current);
            temp->lchild = stack[top--];
            temp->rchild = stack[top--];
            stack[++top] = temp;
        }
    }
    return stack[top];
}

void inorderTraversal(Nodeptr root)
{
    if (root)
    {
        inorderTraversal(root->lchild);
        printf("%c ", root->data);
        inorderTraversal(root->rchild);
    }
}

int main()
{
    Nodeptr root = expression();

    printf("INORDER: ");
    inorderTraversal(root);
}
