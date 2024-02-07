#include <stdio.h>

int main()
{
  int num;
  int units, tens, hundreds;

  printf("Enter a 3-digit number: ");
  scanf("%d", &num);

  units = num % 10;
  tens = (num / 10) % 10;
  hundreds = num / 100;

  printf("Reverse of 3-digit number is %d\n", (units * 100) + (tens * 10) + hundreds);

}