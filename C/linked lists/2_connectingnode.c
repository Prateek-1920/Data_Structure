#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};


int main(){
    struct node *head;
    head = (struct node *)malloc(sizeof(struct  node));
    head->data = 45;
    head->link = NULL;

    struct node *current;
    current = (struct node*)malloc(sizeof(struct  node));
    current->data= 98;
    current->link = NULL;
    head->link = current;

    printf("%d %d",head->data , current->data);
}