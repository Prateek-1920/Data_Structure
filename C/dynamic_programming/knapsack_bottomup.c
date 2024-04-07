#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b ? a : b);
}

int knapsack(int num_obj, int knap_cap, int **table, int *weight, int *profit)
{
    for (int i = 1; i <= num_obj; i++) //i = object 
    {
        for (int w = 1; w <= knap_cap; w++) //w  = current capacity
        {
            if (i == 0 || w == 0)
            {
                table[i][w] = 0;
            }
            else if (weight[i - 1] <= w) 
            {
                table[i][w] = max(profit[i - 1] + table[i - 1][w - weight[i - 1]], table[i - 1][w]);
            }
            else
            {
                table[i][w] = table[i - 1][w];
            }
        }
    }
    int result = table[num_obj][knap_cap];
    return result;
}

int main()
{
    int w, num_obj;
    printf("Enter number of objects: ");
    scanf("%d", &num_obj);

    int *weight = (int *)malloc(num_obj * sizeof(int));
    printf("Enter weights : ");
    for (int i = 0; i < num_obj; i++)
    {
        scanf("%d", &weight[i]);
    }

    int *profits = (int *)malloc(num_obj * sizeof(int));
    printf("Enter profits : ");
    for (int i = 0; i < num_obj; i++)
    {
        scanf("%d", &profits[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &w);

    int **table = (int **)malloc((num_obj + 1) * sizeof(int **));
    for (int i = 0; i <= num_obj; i++)
    {
        table[i] = (int *)malloc((w + 1) * sizeof(int));
    }

    int ans = knapsack(num_obj, w, table, weight, profits);
    printf("Answer : %d\n", ans);
}