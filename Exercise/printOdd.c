#include <stdio.h>

int main() {
    int A = 0;
    int B = 0;

    for (int i = 1; i <= 20; i++) {
        A += 3;
        B += 7;

        if (A % 2 != 0) {
            printf("A: %d\n", A);
        } else {
            printf("B: %d\n", B);
        }

        if (i % 5 == 0) {
            printf("Iteration %d: A = %d, B = %d\n", i, A, B);
        }
    }


    printf("Final values: A = %d, B = %d\n", A, B);

    return 0;
}
