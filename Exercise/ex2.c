#include <stdio.h>

// Swap the value stored in a pointer with the value stored in another pointer without affecting their memory address


// Pointer 2

int main(void) 
{
  int a = 2;
  int b = 4;

  int *a_ptr = &a;
  int *b_ptr = &b;

  int pointer =*a_ptr;
  *a_ptr = *b_ptr;
  *b_ptr = pointer;
  

  // b_ptr = *a_ptr_ptr;

  printf("A pointer: %d\n", *a_ptr);
  printf("B pointer: %d\n", *b_ptr);
}