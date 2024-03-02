#include <stdio.h>

void TOH(int n, char source, char temp, char destination, int *opcount)
{
    (*opcount)++;
    if (n == 1)
    {
        printf("\nDisc 1 moved from %c to %c", source, destination);
        return;
    }
    TOH(n - 1, source, temp, destination, opcount);
    printf("\nDisc %d moved from %c to %c", n, source, destination);
    TOH(n - 1, temp, destination, source, opcount);
}

int main()
{
    int n, opcount = 0;
    printf("Enter number of dicsc: ");
    scanf("%d", &n);
    TOH(n, 'A', 'B', 'C', &opcount);
    printf("\nOperations = %d", opcount);
    return 0;
}