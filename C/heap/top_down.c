#include <stdio.h>

void heapify(int arr[], int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && arr[index] > arr[parent])
    {
        int temp = arr[index];
        arr[index] = arr[parent];
        arr[parent] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

void buildheap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        heapify(arr, i);
    }
}

void printheap(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    buildheap(arr, n);

    printf("Heap is:\n");
    printheap(arr, n);
}