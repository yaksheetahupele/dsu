#include <stdio.h>

int main()
{
    int a[100], n, i, j, max = 0, and;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            and = a[i] & a[j];

            if (and > max)
                max = and;
        }
    }

    printf("Maximum AND value = %d", max);

    return 0;
}