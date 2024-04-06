#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct
{
    int key;
} Node;

void inithash(Node hashtable[])
{
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i].key = -1;
    }
}

int hashfunc(int key)
{
    return key % SIZE;
}

void insert(Node hashtable[], int key)
{
    int i = hashfunc(key);
    while (hashtable[i].key != -1)
    {
        i = (i + 1) % SIZE; // linear probing
    }
    hashtable[i].key = key;
}

int search(Node hashtable[], int key)
{
    int i = hashfunc(key);
    while (hashtable[i].key != -1)
    {
        if (hashtable[i].key == key)
        {
            return 1;
        }
        i++;
    }
    return 0;
}

void print(Node hashtable[])
{
    printf("HASH TABLE \n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d-> ",i);
        if (hashtable[i].key != -1)
        {
            printf("%d", hashtable[i].key);
        }
        printf("\n");
    }
}

int main()
{
    Node hashtable[SIZE];
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

    print(hashtable);
}