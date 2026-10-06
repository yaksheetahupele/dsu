#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50], key[50], longest[50];
    int n, i, j;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    // Insertion Sort - Descending order
    for (i = 1; i < n; i++)
    {
        strcpy(key, a[i]);
        j = i - 1;

        while (j >= 0 && strcmp(a[j], key) < 0)
        {
            strcpy(a[j + 1], a[j]);
            j--;
        }

        strcpy(a[j + 1], key);
    }

    // Find longest string
    strcpy(longest, a[0]);

    for (i = 1; i < n; i++)
    {
        if (strlen(a[i]) > strlen(longest))
            strcpy(longest, a[i]);
    }

    printf("\nStrings in descending order:\n");
    for (i = 0; i < n; i++)
        printf("%s ", a[i]);

    printf("\n\nLongest string = %s", longest);
    printf("\nLength = %d", (int)strlen(longest));

    return 0;
}