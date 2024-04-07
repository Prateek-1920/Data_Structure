#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *rear = NULL;
struct node *front = NULL;

void enqueue()
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &rear->data);
        front = rear;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->link = NULL;
        rear->link = temp;
        rear = temp;
    }
}

void dequeue()
{
    if (front != NULL)
    {
        printf("popped %d ", front->data);
        front = front->link;
    }
    else
    {
        printf("queue empty");
    }
}

void display()
{
    struct node *temp = NULL;
    temp = front;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
    }
}

int main()
{
    int input;
    while (input != -1)
    {
        printf("1. enqueue 2.dequeue 3.display -1.exit");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case -1:
            break;
        }
    }
}