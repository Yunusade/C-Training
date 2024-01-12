//  create a program that crashes by trying to modify read only memory
#include <stdio.h>

int main(void) {
  char *str = "Crash program";
  str[2] = "h";

  printf("%s", str);
  return 0;
}