#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char str[20]; 
    unsigned long result;


    printf("Input a number as a string: ");
    fgets(str, sizeof(str), stdin);

    // This line converts the string into an unsigned long interger
    result = strtoul(str, NULL, 0);

    printf("Converted value: %lu\n", result);

    return 0;
}
