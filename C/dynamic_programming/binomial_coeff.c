#include <stdio.h>

int min(int a, int b)
{
    return (a < b ? a : b);
}

int binomial_coeff(int n, int r)
{
    int C[n + 1][r + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0 || j == i)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][r];
}

int main()
{
    int n, r;
    printf("Enter values of n and r: ");
    scanf("%d%d", &n, &r);

    printf("Value of C(%d,%d) is: %d\n", n, r, binomial_coeff(n, r));

    return 0;
}