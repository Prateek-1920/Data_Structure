#include <stdio.h>

void countingsort(int arr[], int n)
{
    // find max
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // arr of zeros till max
    int count[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // count occurunces
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // cumulative count
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // copy
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
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

int main()
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

    printf("original array is :");
    printarr(arr, n);

    printf("sorted array is :");
    countingsort(arr, n);
    printarr(arr, n);
}