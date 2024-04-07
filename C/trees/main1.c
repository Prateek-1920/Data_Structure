#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *r,*l;
}Node;

Node *getnode()
{
    Node *temp=malloc(sizeof(Node));
    return temp;
}

Node *create(Node *temp,int item)
{
    if(temp==NULL){
    temp=getnode();
    temp->data=item;
    temp->r=temp->l=NULL;
    }
else{
    if(temp->data > item)
        temp->l=create(temp->l,item);
    else if(temp->data < item)
        temp->r=create(temp->r,item);
}
    return temp;
}


void display(Node *root)
{
    if(root)
    {
        display(root->l);
        printf("%d\t",root->data);
        display(root->r);
    }
}
void main()
{
    Node *root=NULL;
    int n,item;
    do
    {
        printf("Enter 0 to display and 1 to enter :\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d",&item);
            root=create(root,item);
            break;
        case 0:
            display(root);
            exit(0);
        }
    }while(1);
}
