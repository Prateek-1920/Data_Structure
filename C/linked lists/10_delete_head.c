#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *add(struct node *ptr, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}

struct node *delete(struct node *head)
{
    if (head== NULL)
    {
        printf("List empty !");
    }
    struct node *temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
    return head;
    printf("Deleted %d", temp->data);
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add(ptr, 55);
    ptr = add(ptr, 65);
    ptr = add(ptr, 75);

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    head = delete (head);

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->link;
    }
}
