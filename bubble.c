#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble(int arr[], int n, int *opcount)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            (*opcount)++;
            if (arr[j] < arr[i])
            {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

int main(int argc, char const *argv[])
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
    bubble(arr, n, &opcount);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    printf("\nOpcount : %d", opcount);
    return 0;
}
