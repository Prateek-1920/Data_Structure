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

void delete(struct node **head, int pos)
{
    struct node *prev = *head;
    struct node *curr = *head;

    if (*head == NULL)
    {
        printf("LL empty");
    }
    else if (pos == 1)
    {
        *head = curr->link;
        free(curr);
        curr = NULL;
    }
    else
    {
        while (pos != 1)
        {
            prev = curr;
            curr = curr->link;
            pos--;
        }
        prev->link = curr->link;
        free(curr);
        curr = NULL;
    }
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
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr = ptr->link;
    }

    printf("\n");

    delete(&head,2);
    ptr = head;
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr = ptr->link;
    }

}
