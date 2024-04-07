#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *r, *l;
} Node;

Node *getNode()
{
    Node *newn = malloc(sizeof(Node));
    return newn;
}

Node *CreateBT(int item)
{
    int x;
    if (item != -1)
    {
        Node *newn = getNode();
        newn->data = item;

        printf("Enter left node of %d : ", item);
        scanf("%d", &x);
        newn->l = CreateBT(x);
        printf("Enter right node of %d : ", item);
        scanf("%d", &x);
        newn->r = CreateBT(x);

        return newn;
    }
    return NULL;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->l);
        printf("%d\t", root->data);
        inorder(root->r);
    }
}

void preorder(Node *root)
{
    if (root)
    {
        printf("%d\t", root->data);
        preorder(root->l);
        preorder(root->r);
    }
}

void postorder(Node *root)
{
    if (root)
    {
        postorder(root->l);
        postorder(root->r);
        printf("%d\t", root->data);
    }
}


int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int left_height = height(root->l);
        int right_height = height(root->r);
        return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
    }
}


int countLeafNodes(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->l == NULL && root->r == NULL)
        return 1;
    return countLeafNodes(root->l) + countLeafNodes(root->r);
}

int main()
{
    Node *root = NULL;
    printf("Enter root node : ");
    int item;
    scanf("%d", &item);
    root = CreateBT(item);

    printf("\nInOrder:\n");
    inorder(root);

    printf("\nPreOrder:\n");
    preorder(root);

    printf("\nPostOrder:\n");
    postorder(root);

    printf("\nHeight of the tree: %d\n", height(root));
    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
