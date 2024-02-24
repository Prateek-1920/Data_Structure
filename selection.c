#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sel_sort(int arr[], int n, int *opcount)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            (*opcount)++;

            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
            if (min_index != i)
            {
                swap(&arr[min_index], &arr[i]);
            }
        }
    }
}

int main()
{
    int n, opcount = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sel_sort(arr, n, &opcount);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Opcount = %d", opcount);
    return 0;
}