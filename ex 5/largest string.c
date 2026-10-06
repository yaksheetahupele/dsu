#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][50];
    int n, i, largest = 0;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings: ");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);

    for (i = 1; i < n; i++)
    {
        if (strlen(a[i]) > strlen(a[largest]))
            largest = i;
    }

    printf("Largest string = %s", a[largest]);

    return 0;
}