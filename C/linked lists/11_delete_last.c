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
    if (head == NULL) // no node
    {
        printf("List empty !");
    }
    else if (head->link == NULL) // one node
    {
        printf("Deleted %d", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        // struct node *temp = head;  //using 2 pointers
        // struct node *temp2 = head;
        // while (temp->link != NULL)
        // {
        //     temp2 = temp;
        //     temp = temp->link;
        // }
        // printf("Deleted %d", temp->data);
        // temp2->link = NULL;
        // free(temp);
        // temp = NULL;

        struct node *temp = head;
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        printf("Deleted %d", temp->link->data);
        free(temp->link);
        temp->link = NULL;
    }
    return head;
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

    printf("\n");

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->link;
    }
}
