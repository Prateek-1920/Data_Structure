#include <stdio.h>

int compute(float n, int *opcount)
{
    int i, result;

    for (i = 0; i < n; i++)
    {
        (*opcount)++;
        if (i * i <= n)
            result = i;
    }

    return result;
}

int main()
{
    int n, opcount = 0;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("\nRoot is :%d", compute(n, &opcount));
    printf("\nOpcount :%d", opcount);
    return 0;
}