#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], temp[50];
    int n, i, j, k, result;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings: ");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            k = 0;
            result = 0;

            while (a[j][k] != '\0' && a[j + 1][k] != '\0')
            {
                if (a[j][k] != a[j + 1][k])
                {
                    result = a[j][k] - a[j + 1][k];
                    break;
                }
                k++;
            }

            if (result == 0)
            {
                if (a[j][k] == '\0' && a[j + 1][k] != '\0')
                    result = -1;
                else if (a[j][k] != '\0' && a[j + 1][k] == '\0')
                    result = 1;
            }

            if (result > 0)
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

    return 0;
}