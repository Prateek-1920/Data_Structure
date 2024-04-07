#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *add(struct node *ptr, int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->link = NULL;
    ptr->link = temp;
    return temp; // returns a node
}

int main()
{
    int h, n;
    printf("Enter head numebr: ");
    scanf("%d", &h);

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = h;
    head->link = NULL;

    struct node *ptr = head;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        int e;
        scanf("%d", &e);
        ptr = add(ptr, e);
    }

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}