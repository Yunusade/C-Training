#include <stdio.h>
#include <math.h>

// Coverting a temperature in celsius to Fahrenhiet and kelvin
// Formula	(6°C × 9/5) + 32

void convert(int celsius) {
   float fahrenhiet = (celsius * 1.8) + 32;
  printf("%f", fahrenhiet);
}

int main(void) {
  convert(3);
  return 0;
}