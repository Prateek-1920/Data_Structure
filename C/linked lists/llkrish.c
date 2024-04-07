#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

Node *head=NULL;
Node *tail=NULL;

void insert(int data)
{
    Node *temp=malloc(sizeof(Node));
    temp->data=data;
    temp->link=NULL;
    
    if(head==NULL) head=tail=temp;
    else
    {
        tail->link=temp;
        tail=temp;
    }
}
void display()
{
    while(head)
    {
        printf("%d\t",head->data);
        head=head->link;
    }
}
void main()
{
    int n,item;
    do
    {
        printf("Enter 1 to enter element and 0 to stop and display:\n");
        scanf("%d",&n);
        if(n==1)
        {
            printf("Enter element: ");
            scanf("%d",&item);
            insert(item);
        }
        if(n==0)
        {
            display();
            exit(0);
        }
    }while(1);
}
