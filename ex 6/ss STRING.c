#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], temp[50];
    int n, i, j, min;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings: ");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (strcmp(a[j], a[min]) < 0)
                min = j;
        }

        if (min != i)
        {
            strcpy(temp, a[i]);
            strcpy(a[i], a[min]);
            strcpy(a[min], temp);
        }
    }

    printf("Sorted strings: ");
    for (i = 0; i < n; i++)
        printf("%s ", a[i]);

    return 0;
}