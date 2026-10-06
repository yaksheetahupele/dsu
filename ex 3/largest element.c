#include <stdio.h>

int main()
{
    int a[100], n, i, largest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    largest = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] > largest)
            largest = a[i];
    }

    printf("Largest element = %d", largest);

    return 0;
}