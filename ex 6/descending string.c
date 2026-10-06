#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], temp[50];
    int n, i, j, max;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings: ");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

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
            strcpy(a[max], temp);
        }
    }

    printf("Strings in descending order: ");
    for (i = 0; i < n; i++)
        printf("%s ", a[i]);

    return 0;
}