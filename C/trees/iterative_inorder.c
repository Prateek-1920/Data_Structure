#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;

struct node
{
    int data;
    Nodeptr lchild;
    Nodeptr rchild;
};

typedef struct
{
    Nodeptr arr[100];
    int top;
} STACK;

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

void push(STACK *s, Nodeptr temp)
{
    if (s->top == 99)
    {
        printf("STACK OVERFLOW");
        return;
    }
    else
    {
        s->top = s->top + 1;
        s->arr[s->top] = temp;
    }
}

Nodeptr pop(STACK *s)
{
    if (s->top == -1)
    {
        printf("STACK UNDERFLOW");
        // return;
        // exit(1);
    }
    else
    {
        return (s->arr[(s->top--)]);
    }
}

Nodeptr iter_inor(Nodeptr root)
{
    Nodeptr temp;
    int done = 0;
    STACK s;
    s.top = -1;

    if (root == NULL)
    {
        printf("EMPTY TREE");
    }

    temp = root;
    while (!done)
    {
        while (temp != NULL)
        {
            push(&s, temp);
            temp = temp->lchild;
        }

        if (s.top != -1)
        {
            temp = pop(&s);
            printf("%d", temp->data);
            temp = temp->rchild;
        }
        else
        {
            done = 1;
        }
    }
}

int main()
{
    int x;
    Nodeptr root = NULL;
    printf("Enter root: ");
    scanf("%d", &x);
    root = createtree(x);

    printf("ITER INOR: ");
    iter_inor(root);
}