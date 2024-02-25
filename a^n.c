#include <stdio.h>

int power(int a, int n)
{
    if (n == 1)
    {
        return a;
    }
    else
    {
        return a * power(a, n - 1);
    }
}

int main()
{
    int a, n;
    printf("Enter the values for a and n where a^n: ");
    scanf("%d%d", &a, &n);
    printf("Value of a^n : %d", power(a, n));

    return 0;
}