#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if ((num & 1) == 0)
        printf("Number is divisible by 2");
    else
        printf("Number is not divisible by 2");

    return 0;
}