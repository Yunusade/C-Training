#include <stdio.h>
#include <stdlib.h>

int main()
{
  int date[3] = {1, 2, 2000};
  int date2[3];

  int i;

  for(i =0; i < 3; i++){
    date2[i] = date[i];
  }

  return 0;
}