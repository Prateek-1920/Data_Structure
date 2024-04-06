#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node
{
    int key;
    struct Node *next;
} Node;

void inithash(Node *hashtable[])
{
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = NULL;
    }
}

int hashfunc(int key)
{
    return key % SIZE;
}

void insert(Node *hashtable[], int key)
{
    int i = hashfunc(key);
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->key = key;
    newnode->next = NULL;

    if (hashtable[i] == NULL)
    {
        hashtable[i] = newnode;
    }
    else
    {
        Node *current = hashtable[i];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
}

int search(Node *hashtable[], int key)
{
    int i = hashfunc(key);
    Node *current = hashtable[i];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void display(Node *hashtable[])
{
    printf("HASH TABLE:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d -> ", i);
        Node *current = hashtable[i];
        while (current != NULL)
        {
            printf("%d ", current->key);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    Node *hashtable[SIZE];
    inithash(hashtable);
    int n, key;
    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter keys: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(hashtable, key);
    }

    display(hashtable);

    printf("Enter key to search: ");
    scanf("%d", &key);
    int res = search(hashtable, key);
    if (res == 1)
    {
        printf("Key found.");
    }
    else
    {
        printf("Key not found.");
    }
}