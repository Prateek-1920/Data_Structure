#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *rlink, *llink;
} Node;

Node *head = NULL;
Node *tail = NULL;

void insert(int data) {
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->rlink = temp->llink = NULL;
    if (head == NULL) {
        head = tail = temp;
    } else {
        tail->rlink = temp;
        temp->llink = tail;
        tail = temp;
    }
}

void display() {
    Node *temp = head;
    printf("Going front:\n");
    while (temp) {
        printf("%d\t", temp->data);
        temp = temp->rlink;
    }

    temp = tail;
    printf("\nGoing back:\n");
    while (temp) {
        printf("%d\t", temp->data);
        temp = temp->llink;
    }
    printf("\n");
}

int main() {
    int n, value;
    do {
        printf("Enter 1 to insert and 2 to display and 0 to exit: ");
        scanf("%d", &n);
        switch (n) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            display();
            break;
        }
    } while (n != 0);

    while (head) {
        Node *temp = head;
        head = head->rlink;
        free(temp);
    }

    return 0;
}

