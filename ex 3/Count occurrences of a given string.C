#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], search[50];
    int n, i, count = 0;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    printf("Enter string to search: ");
    scanf("%s", search);

    for (i = 0; i < n; i++)
    {
        if (strcmp(a[i], search) == 0)
            count++;
    }

    printf("Number of occurrences = %d", count);

    return 0;
}