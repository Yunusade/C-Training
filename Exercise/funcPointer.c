#include <stdio.h>

// Function prototypes
void function1();
void function2();
void function3();

// Function pointer table
void (*functionTable[])(void) = {
    function1,
    function2,
    function3
};

// Get the function pointer
void (*getFunctionPointer(int index))(void) {
    // I used ternary operators and this code is checking if the index is within the bounds of the functionTable array
    return (index >= 0 && index < sizeof(functionTable) / sizeof(functionTable[0])) ? functionTable[index] : NULL;
}

// Example functions
void function1() {
    printf("Function 1\n");
}

void function2() {
    printf("Function 2\n");
}

void function3() {
    printf("Function 3\n");
}

int main() {

    int index = 3; 
    void (*selectedFunction)(void) = getFunctionPointer(index);

    if (selectedFunction != NULL) {
        selectedFunction();
    } else {
        printf("Index out of bounds try again!!!\n");
    }

    return 0;
}
