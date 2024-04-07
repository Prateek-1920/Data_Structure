#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head, *current , *newnode;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 100;
    head->link = NULL;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 150;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 200;
    current->link = NULL;
    head->link->link = current;


    struct node *temp = NULL;
    printf("LL before inserting node at the end:\n");
    temp = head; //reinitialize
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->link;
    }

    current = malloc(sizeof(struct node));
    current->data = 250;
    current->link = NULL;
   // head->link->link->link = current;// instead of this use temp to traverse to the end of the list

    temp = head;
    while(temp->link!=NULL){ //link traversal not NODE
        temp=temp->link;    
    }
    temp->link = current;

    printf("LL AFTER inserting node at the end:\n");
    temp = head; //reinitialize
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->link;
    }




    


}