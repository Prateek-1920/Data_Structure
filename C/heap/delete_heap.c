#include <stdio.h>

void heapify(int arr[], int index)
{
    int parent = index / 2;
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

void detele(int arr[], int n)
{
    int e, index, flag = 0;
    printf("Enter element to delete: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == e)
        {
            index = i;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("Element not found.");
    }
    else
    {
        arr[index] = arr[n - 1];
        heapify(arr, n - 1);
    }
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

    detele(arr, n);
    printf("Heap after deletion is: \n");
    printheap(arr, n-1);
}