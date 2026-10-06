#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], temp[50];
    int n, i, j, k, max, result;

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
            k = 0;
            result = 0;

            while (a[j][k] != '\0' && a[max][k] != '\0')
            {
                if (a[j][k] != a[max][k])
                {
                    result = a[j][k] - a[max][k];
                    break;
                }
                k++;
            }

            if (result == 0)
            {
                if (a[j][k] != '\0' && a[max][k] == '\0')
                    result = 1;
            }

            if (result > 0)
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