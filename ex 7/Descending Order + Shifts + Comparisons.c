#include <stdio.h>

int main()
{
    int a[100], n, i, j, key;
    int shifts = 0, comparisons = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (a[j] > key)
                break;

            a[j + 1] = a[j];
            shifts++;
            j--;
        }

        a[j + 1] = key;
    }

    printf("Sorted array in descending order: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTotal shifts = %d", shifts);
    printf("\nTotal comparisons = %d", comparisons);

    return 0;
}