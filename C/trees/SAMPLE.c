#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

// Node structure for binary tree
typedef struct node *Nodeptr;
struct node
{
    int data;
    Nodeptr rchild;
    Nodeptr lchild;
};

// Node structure for stack
typedef struct
{
    Nodeptr arr[100]; // Assuming a maximum of 100 nodes in the stack
    int top;
} STACK;

Nodeptr getnode();
Nodeptr CreateBinaryTree(int item);
void Inorder(Nodeptr root);
void Preorder(Nodeptr root);
void Postorder(Nodeptr root);
void iterative_inorder(Nodeptr root);
void InitializeStack(STACK *s);
int IsEmptyStack(STACK *s);
void Push(STACK *s, Nodeptr node);
Nodeptr Pop(STACK *s);

// Function to allocate memory for a new node
Nodeptr getnode()
{
    return ((Nodeptr)malloc(sizeof(struct node)));
}

// Function to create a binary tree
Nodeptr CreateBinaryTree(int item)
{
    int x;
    if (item != -1)
    {
        Nodeptr temp = getnode();
        temp->data = item;
        printf("Enter the lchild of %d: ", item);
        scanf("%d", &x);
        temp->lchild = CreateBinaryTree(x);
        printf("Enter the rchild of %d: ", item);
        scanf("%d", &x);
        temp->rchild = CreateBinaryTree(x);
        return temp;
    }
    return NULL;
}

// Function to perform inorder traversal recursively
void Inorder(Nodeptr root)
{
    if (root)
    {
        Inorder(root->lchild);
        printf("%d\n", root->data);
        Inorder(root->rchild);
    }
}

// Function to perform preorder traversal recursively
void Preorder(Nodeptr root)
{
    if (root)
    {
        printf("%d\n", root->data);
        Preorder(root->lchild);
        Preorder(root->rchild);
    }
}

// Function to perform postorder traversal recursively
void Postorder(Nodeptr root)
{
    if (root)
    {
        Postorder(root->lchild);
        Postorder(root->rchild);
        printf("%d ", root->data);
    }
}

// Function to perform iterative inorder traversal using a stack
void iterative_inorder(Nodeptr root)
{
    Nodeptr cur;
    int done = false;
    STACK s;
    s.top = -1;

    if (root == NULL)
    {
        printf("Empty Tree\n");
        return;
    }

    cur = root;
    while (!done)
    {
        while (cur != NULL)
        {
            Push(&s, cur);
            cur = cur->lchild;
        }

        if (!IsEmptyStack(&s))
        {
            cur = Pop(&s);
            printf("%d ", cur->data);
            cur = cur->rchild;
        }
        else
        {
            done = true;
        }
    }
}

// Function to initialize an empty stack
void InitializeStack(STACK *s)
{
    s->top = -1;
}

// Function to check if the stack is empty
int IsEmptyStack(STACK *s)
{
    return (s->top == -1);
}

// Function to push a node onto the stack
void Push(STACK *s, Nodeptr node)
{
    if (s->top == 99)
    {
        printf("Stack Overflow\n");
        return;
    }

    s->arr[++(s->top)] = node;
}

// Function to pop a node from the stack
Nodeptr Pop(STACK *s)
{
    if (IsEmptyStack(s))
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    return s->arr[(s->top)--];
}

int main()
{
    Nodeptr root = NULL;
    int item;

    printf("Creating the tree [enter -1 for NULL]: \n");
    scanf("%d", &item);
    fflush(stdin);
    root = CreateBinaryTree(item);

    printf("\nInorder Traversal:\n");
    Inorder(root);

    printf("\nPreorder Traversal:\n");
    Preorder(root);

    printf("\nPostorder Traversal:\n");
    Postorder(root);

    printf("\nIterative Inorder Traversal:\n");
    iterative_inorder(root);

    return 0;
}
