#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], search[50];
    int n, i, low, high, mid, found = 0;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings in descending order:\n");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    printf("Enter string to search: ");
    scanf("%s", search);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (strcmp(a[mid], search) == 0)
        {
            printf("String found at position %d", mid + 1);
            found = 1;
            break;
        }
        else if (strcmp(search, a[mid]) > 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (found == 0)
        printf("String not found");

    return 0;
}