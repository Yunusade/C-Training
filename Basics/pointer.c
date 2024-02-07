#include <stdio.h>
#include <stdlib.h>

int main ()
{
  float num1 = 5, num2 = 7;
  float *ptrA, *ptrB;

  printf("num1 = %f, num2 = %f \n", num1, num2);

  ptrA = &num1;
  ptrB = &num2;

  printf("num1 = %f, num2 = %f \n", *ptrA, * ptrB);

  *ptrA = 3;
  *ptrB = *ptrB + 1;

  printf("num1 = %f, num2 = %f \n", num1, num2);
}