#include <stdio.h>

// In a void function, add two values and then print that value in main


void addNum(int a, int b, int *pointer) {
  *pointer = a + b;
}

int main(void) {
  int result;
  addNum(1, 6, &result);
  printf("%d\n", result);
  return 0;
}