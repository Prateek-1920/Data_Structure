#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front = 0;
struct node *rear = 0;

void enqueue()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = 0;

    if (front == 0 && rear == 0)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void dequeue()
{
    struct node *temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Queue empty");
    }
    else
    {
        printf("popped %d \n", temp->data);
        front = front->link;
        free(temp);
    }
}

void display()
{
    struct node *temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Queue empty");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d  ", temp->data);
            temp = temp->link;
        }
    }
}

int main()
{
    int input;
    while (input != -1)
    {
        printf("1.enqueqe 2.dequque 3.display\n");
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
        }
    }
}