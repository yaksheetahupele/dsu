#include <stdio.h>

int main()
{
    int a[100], n, i, j, max, temp;
    int largest, smallest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Selection sort in descending order
    for (i = 0; i < n - 1; i++)
    {
        max = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[max])
                max = j;
        }

        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
    }

    largest = a[0];
    smallest = a[n - 1];

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nLargest element = %d", largest);
    printf("\nSmallest element = %d", smallest);

    return 0;
}