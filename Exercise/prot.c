#include <stdio.h>

// Consider that a 2 bytes variable Prot is composed of 3 fields (Type, Priority and ID) as shown below. Write a program that prints the values of of these 3 fields (Type, Priority and ID) if Prot = 0xB7B2.

int main() {
    unsigned int Prot = 0xB7B2;



    // Using bitwise with masks and shift operations to extract values
    unsigned int Type = (Prot >> 10) & 0x3F;     // 0x3F = 0011 1111
    unsigned int Priority = (Prot >> 7) & 0x7;  // 0x07 = 0000 0111
    unsigned int ID = Prot & 0x7F;               // 0x7F = 0111 1111

    printf("Type: %u\n", Type);
    printf("Priority: %u\n", Priority);
    printf("ID: %u\n", ID);


    return 0;
}