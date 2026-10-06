#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, n, i, search, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++)
    {
        if (a[i] == search)
        {
            printf("Element found at position %d", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Element not found");

    free(a);

    return 0;
}