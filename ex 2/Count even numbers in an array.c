#include <stdio.h>

int main()
{
    int a[100], n, i, count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if ((a[i] & 1) == 0)
            count++;
    }

    printf("Number of even elements = %d", count);

    return 0;
}