#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data=55;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 65;
    current->link=NULL;
    head->link->link = current;

    int count=0;
    struct node *temp;
    temp = head;
    while(temp !=NULL){
        count++;
        temp=temp->link;
    }
    printf("NODES = %d", count);

    
}