#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], temp[50];
    int n, i, j, max, longest;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings: ");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    // Selection sort in descending order
    for (i = 0; i < n - 1; i++)
    {
        max = i;

        for (j = i + 1; j < n; j++)
        {
            if (strcmp(a[j], a[max]) > 0)
                max = j;
        }

        if (max != i)
        {
            strcpy(temp, a[i]);
            strcpy(a[i], a[max]);
            strcpy(a[max], a[temp]);
        }
    }

    // Find longest string
    longest = 0;

    for (i = 1; i < n; i++)
    {
        if (strlen(a[i]) > strlen(a[longest]))
            longest = i;
    }

    printf("Sorted strings: ");
    for (i = 0; i < n; i++)
        printf("%s ", a[i]);

    printf("\nLongest string = %s", a[longest]);

    return 0;
}