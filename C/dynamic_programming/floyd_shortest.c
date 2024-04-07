#include <stdio.h>
#include <stdlib.h>

#define INF 100000

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void warshall(int **p, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                p[i][j] = min(p[i][j], (p[i][k] + p[k][j]));
            }
        }
    }
}

void printmat(int **p, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d          ", p[i][j]);
        }
        printf("\n\n");
    }
}

int main()
{
    int n, e, u, v, w;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int **p = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        p[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                p[i][j] = 0;
            }
            else
            {
                p[i][j] = INF;
            }
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        printf("Enter src dest and weight for edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        p[u][v] = w;
    }

    printf("Matrix is : ");
    printmat(p, n);

    warshall(p, n);
    printf("Resultant Matrix:");
    printmat(p, n);
}