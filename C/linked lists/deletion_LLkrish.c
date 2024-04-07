#include<stdio.h>
#include<stdlib.h>

typedef struct tempnode
{
    int data;
    struct tempnode* next;
}Node;

void LinkedListTraversal(Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

//1
Node* DeleteFirst(Node* head)
{
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr = head;
    head=head->next;
    free(ptr);
    return head;
}

Node* DeleteAtIndex(Node *head,int index)
{
    Node* p = head;
    Node* q = head->next;
    for(int i = 0;i<index-1;i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

Node* DeleteLast(Node* head)
{
    Node* p = head;
    Node* q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
Node* DeleteValue(Node* head,int value)
{
    Node* p = head;
    Node* q = head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data == value)
    {
        p->next = q->next;
    }
    return head;
}

int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node* fourth;

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    fourth = (Node*)malloc(sizeof(Node));

    head->data = 4;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 7;
    fourth->next = NULL;

    LinkedListTraversal(head);
    //1 head = DeleteFirst(head);
    //2 head = DeleteAtIndex(head,2);
    //3 head = DeleteLast(head);
    head = DeleteValue(head,6);
    printf("\nNew LL\n");
    LinkedListTraversal(head);

    free(head);
    free(second);
    free(third);

    return 0;

}
