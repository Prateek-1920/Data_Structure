#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *addlast(struct node *head, int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;

    head->link = temp;

    return temp;
}

struct node *addbeg(struct node *head, int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = head;
    head = temp;

    return head;
}

struct node *addpos(struct node *head, int pos, int item)
{
    struct node *temp;
    temp = head;
    int i = 0;
    while (i != (pos - 1))
    {
        temp = temp->link;
        i++;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;

    newnode->link = temp->link;
    temp->link = newnode;
    return head;
}

struct node *dellast(struct node *head)
{
    if (head == NULL)
    {
        printf("LIST EMPTY");
    }
    else if (head->link == NULL)
    {
        printf("Deleted %d.", head->data);
        free(head);
    }
    else
    {
        struct node *temp = head;
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        printf("deletec %d.", temp->link->data);
        free(temp->link);
        temp->link = NULL;
    }
    return head;
}

struct node *delbeg(struct node *head)
{
    if (head == NULL)
    {
        printf("LIST EMPTY");
    }
    else if (head->link == NULL)
    {
        free(head);
    }
    else
    {
        struct node *temp;
        temp = head;
        head = temp->link;
        free(temp);
    }
    return head;
}

struct node *delpos(struct node *head, int pos)
{
    struct node *temp = head;
    int i = 1;
    while (i != (pos - 1))
    {
        temp = temp->link;
        i++;
    }
    struct node *todelete;
    todelete = temp->link;
    temp->link = todelete->link;

    return temp;
}

struct node *reverse(struct node *head)
{

    if (head == NULL || head->link == NULL)
    {
        return head;
    }
    struct node *revlist = reverse(head->link);

    head->link->link = head;
    head->link = NULL;

    return revlist;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of head: ");
    int h;
    scanf("%d", &h);
    head->data = h;
    head->link = NULL;

    printf("Enter number of elements in LL: ");
    int n;
    scanf("%d", &n);
    struct node *ptr = head;

    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Enter element: ");
        scanf("%d", &x);
        ptr = addlast(ptr, x);
    }

    printf("Before adding ");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->link;
    }

    ptr = head;
    int e, p;
    printf("Add position and element: ");
    scanf("%d", &p);
    scanf("%d", &e);
    head = addpos(head, p, e);

    // head = reverse(head);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->link;
    }
}