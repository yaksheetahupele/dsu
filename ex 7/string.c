#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], key[50];
    int n, i, j;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    for (i = 1; i < n; i++)
    {
        strcpy(key, a[i]);
        j = i - 1;

        while (j >= 0 && strcmp(a[j], key) > 0)
        {
            strcpy(a[j + 1], a[j]);
            j--;
        }

        strcpy(a[j + 1], key);
    }

    printf("Sorted strings: ");
    for (i = 0; i < n; i++)
        printf("%s ", a[i]);

    return 0;
}