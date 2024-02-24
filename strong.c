#include <stdio.h>

int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int extractfact(int n)
{
    int ans = 0, div, rem;
    int temp = n;
    while (temp != 0)
    {
        rem = temp % 10;
        temp = temp / 10;
        ans += fact(rem);
    }
    return ans;
}

void strong(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == extractfact(arr[i]))
        {
            printf("strong number = %d\n", arr[i]);
        }
        else
        {
            printf("Not a strong number\n");
        }
    }
}

int main()
{
    int n;
    printf("Enetr number of elelments in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elelments: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    strong(arr, n);
}