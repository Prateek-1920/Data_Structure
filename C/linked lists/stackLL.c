#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = 0;

void push()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to push: ");
    scanf("%d", &temp->data);
    temp->link = top;
    top = temp;
}

void pop()
{
    struct node *temp;
    temp = top;
    printf("popped: %d", top->data);
    top = top->link;
    free(temp);
}

void display()
{
    struct node *ptr = top;
    while (ptr != 0)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{
    int input;
    while (input != -1)
    {
        printf("1.push 2.pop 3.display: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    }
}