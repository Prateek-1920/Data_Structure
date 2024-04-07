#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b ? a : b);
}

void warshall(int **p, int n)
{
    for (int k = 0; k < n; k++) // intermediate
    {
        for (int i = 0; i < n; i++) // source
        {
            for (int j = 0; j < n; j++) // dest
            {
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
            }
        }
    }
}

int main()
{
    int n, e, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int **p = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        p[i] = (int *)malloc(n * (sizeof(int)));
        for (int j = 0; j < n; j++)
        {
            p[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        printf("Enter src and dest for edge %d", i + 1);
        scanf("%d%d", &u, &v);
        p[u][v] = 1;
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }

    warshall(p, n);

    printf("\nTransitive closure:\n");
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < e; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }
}