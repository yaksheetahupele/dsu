#include <stdio.h>

int main()
{
    int a[100], n, i, j, max, temp, swaps = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n - 1; i++)
    {
        max = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[max])
                max = j;
        }

        if (max != i)
        {
            temp = a[i];
            a[i] = a[max];
            a[max] = temp;

            swaps++;
        }
    }

    printf("Sorted array in descending order: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTotal swaps = %d", swaps);

    return 0;
}