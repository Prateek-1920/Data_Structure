#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[parent])
    {
        parent = left;
    }
    if (right < n && arr[right] > arr[parent])
    {
        parent = right;
    }
    if (parent != i)
    {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;

        heapify(arr, n, parent);
    }
}

void buildheap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void heapsort(int arr[], int n)
{
    buildheap(arr, n);
    printf("Original heap: ");
    printarr(arr, n);

    for (int i = n-1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
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

    heapsort(arr, n);

    printf("Sorted Heap is:\n");
    printarr(arr, n);
}
