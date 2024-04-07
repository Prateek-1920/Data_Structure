#include <stdio.h>
#include <string.h>

void getshifttable(char pattern[], int shift[], int patt_len)
{
    for (int i = 0; i < 127; i++)
    {
        shift[i] = patt_len;
    }

    for (int i = 0; i < patt_len - 1; i++)
    {
        shift[pattern[i]] = patt_len - 1 - i;
    }
}

int horspool(char text[], char pattern[], int *opcount)
{
    int txt_len = strlen(text);
    int patt_len = strlen(pattern); // pattern length
    int shift[127];

    getshifttable(pattern, shift, patt_len);

    int i = patt_len - 1;
    while (i < txt_len)
    {
        int k = 0;
        while (k < patt_len && pattern[patt_len - 1 - k] == text[i - k])
        {
            k++;
        }
        (*opcount) += k + 1;

        if (k == patt_len)
        {
            return (i - patt_len + 1);
        }
        else
        {
            i = i + shift[text[i]];
        }
    }
    return -1;
}

int main()
{
    char text[100], pattern[100];
    int opcount = 0;
    printf("Enter string: ");
    scanf(" %[^\n]", text);
    printf("Enter pattern: ");
    scanf(" %[^\n]", pattern);
    int pos = horspool(text, pattern, &opcount);
    if (pos == -1)
    {
        printf("Pattern not found. Comparison done = %d\n", opcount);
    }
    else
    {
        printf("Pattern found at position %d\nComparisons done = %d\n", pos, opcount);
    }

    return 0;
}
