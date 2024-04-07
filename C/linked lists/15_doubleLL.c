#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *add(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = 45;
    ptr->next = NULL;

    ptr = head;
    return head;
}

int main(){
    struct node* head = NULL;
    head = add(head , 55);
    head = add(head , 65);
    head = add(head , 75);

}