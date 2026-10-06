#include <stdio.h>

int main()
{
    int num, n;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter the bit position : ");
    scanf("%d", &n);

    if (num & (1 << n))
        printf("Bit at position %d is SET", n);
    else
        printf("Bit at position %d is CLEAR", n);

    return 0;
}