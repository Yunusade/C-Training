#include <stdio.h>

int main(void){
  int age;
  int year;

  printf("What year is it?: ");
  scanf("%d", &year);
  printf("How old are you?: ");
  scanf("%d", &age);

  int result = year - age;
  printf("You were born in %d", result);
}