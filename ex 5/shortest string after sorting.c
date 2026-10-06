#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], temp[50];
    int n, i, j, shortest;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings: ");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    // Bubble sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }

    // Find shortest string
    shortest = 0;

    for (i = 1; i < n; i++)
    {
        if (strlen(a[i]) < strlen(a[shortest]))
            shortest = i;
    }

    printf("Sorted strings: ");
    for (i = 0; i < n; i++)
        printf("%s ", a[i]);

    printf("\nShortest string = %s", a[shortest]);

    return 0;
}