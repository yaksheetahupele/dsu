#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], temp[50];
    int n, i, j, comparisons = 0;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings: ");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (strcmp(a[j], a[j + 1]) > 0)
            {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }

    printf("Sorted strings: ");
    for (i = 0; i < n; i++)
        printf("%s ", a[i]);

    printf("\nTotal comparisons = %d", comparisons);

    return 0;
}