#include <stdio.h>
#include <stdlib.h>

typedef struct tempnode {
    int data;
    struct tempnode* next;
}Node;

void LinkedListTraversal(Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

Node* InsertAtFirst(Node *head, int data) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

Node* insertAtIndex(Node *head, int data, int index) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    Node* p = head;
    int i = 0;

    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

Node* insertAtEnd(Node *head, int data) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

Node* insertAfterNode(Node* head, Node* prevNode, int data) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// Free the entire linked list
void freeLinkedList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int choice, data, index;
    Node* temp;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at a specific position\n");
        printf("3. Insert at the end\n");
        printf("4. Insert after a specific node\n");
        printf("5. Display the linked list\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = InsertAtFirst(head, data);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the index to insert at: ");
                scanf("%d", &index);
                head = insertAtIndex(head, data, index);
                break;

            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 4:
                printf("Enter data to insert after a specific node: ");
                scanf("%d", &data);
                printf("Enter the data of the node after which to insert: ");
                scanf("%d", &index);
                temp = head;
                while (temp != NULL && temp->data != index) {
                    temp = temp->next;
                }
                if (temp != NULL) {
                    head = insertAfterNode(head, temp, data);
                } else {
                    printf("Node not found!\n");
                }
                break;

            case 5:
                printf("Linked List:\n");
                LinkedListTraversal(head);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);

    // Free the entire linked list before exiting
    freeLinkedList(head);

    return 0;
}
