#include <stdio.h>

int fib(int n, int *op)
{
    (*op)++;
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1, op) + fib(n - 2, op);
    }
}

int main()
{
    int n, op = 0;
    printf("Enter n\n");
    scanf("%d", &n);

    printf("%d\n", fib(n, &op));
    printf("opcount = %d", op);
}