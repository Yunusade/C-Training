#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  double num1;
  double num2;
  char operator;

  printf("Enter a number: ");
  scanf("%lf",  &num1);
  printf("Enter operator: ");
  scanf(" %c", &operator);
  printf("Enter a number: ");
  scanf("%lf", &num2);

  if(operator == '+') {
    printf("%f\n", num1 + num2);
  }else if(operator == '-'){
    printf("%f\n", num1 - num2);
  }else if(operator == '/'){
    printf("%f\n", num1 / num2);
  }else if(operator == '*'){
    printf("%f\n", num1 * num2);
  }else {
    printf("Invalid Operator\n");
  }


  return 0;
}