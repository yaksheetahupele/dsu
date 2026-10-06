#include <stdio.h>

int main()
{
    int a[100], n, i, j, max = 0, or;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            or = a[i] | a[j];

            if (or > max)
                max = or;
        }
    }

    printf("Maximum OR value = %d", max);

    return 0;
}