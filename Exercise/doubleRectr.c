#include <stdio.h>

int main(void){
  double a = 5.2;
  double b = 9.6;

  double temp;

  temp = a;
  a = b;
  b = temp;


  printf("%lf, %lf", a, b);
}