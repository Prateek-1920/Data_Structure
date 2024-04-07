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

struct node *add_pos(struct node *ptr, int pos, int data)
{
    struct node *head = ptr;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    pos--;
    while (pos != 1)
    {
        head = head->link;
        pos--;
    }
    temp->link = head->link;
    head->link = temp;
    return temp;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *pointer = head;
    pointer = add(pointer, 55);
    pointer = add(pointer, 65);

    pointer = head;
    while (pointer != NULL)
    {
        printf("%d\t", pointer->data);
        pointer = pointer->link;
    }

    printf("\n");
    pointer = head;
    pointer = add_pos(head, 3, 100);
    pointer = head;
    while (pointer != NULL)
    {
        printf("%d\t", pointer->data);
        pointer = pointer->link;
    }
}
