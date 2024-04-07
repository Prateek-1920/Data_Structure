#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = 55;
    ptr->link = NULL;

    ptr->link = head;
    head = ptr;
    while(ptr!= NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
}