#include <stdio.h>

int main()
{
    int a[100], n, i, search, comparisons = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++)
    {
        comparisons++;

        if (a[i] == search)
        {
            printf("Element found at position %d\n", i + 1);
            break;
        }
    }

    printf("Number of comparisons = %d", comparisons);

    return 0;
}