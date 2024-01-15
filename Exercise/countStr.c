#include <stdio.h>

int main(void)
{
    char str[] = "Hello World";
    int count = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        count++;
        i++;
    }
    printf("The length of the string is %d\n", count);
    return 0;
}