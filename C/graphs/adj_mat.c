#include <stdio.h>

int main()
{
    int n, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj_mat[n][n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter source and destination: ");
        scanf("%d%d", &src, &dest);
        adj_mat[src][dest] = 1;
        adj_mat[dest][src] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_mat[i][j] != 1)
            {
                adj_mat[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", adj_mat[i][j]);
        }
        printf("\n");
    }
}
