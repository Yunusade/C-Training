// Sn = (a1 + an) * n/2

#include <stdio.h>

int main() {
  int a1, an, d;
  float n;

  a1 = 1;
  d = 2;
  n = 9;
  an = 17;
  printf("Sum of arithmetic sequence %f\n", (a1 + an) * n/2);
  return 0;
}