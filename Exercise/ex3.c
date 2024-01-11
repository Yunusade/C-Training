#include <stdio.h>
int *pointer;
void swap(int **pointerA, int **pointerB){
  pointer= *pointerA;

  *pointerA = *pointerB;
  *pointerB = pointer;
}

int main(void) {
  int a = 6;
  int b = 7;

  int *a_ptr = &a;
  int *b_ptr = &b;

  swap(&a_ptr, &b_ptr);
  printf("%d\n", *a_ptr);
  printf("%d\n", *b_ptr);
  return 0;
}