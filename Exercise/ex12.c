#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void createSon(int id) {
  printf("I'm the son %d\n", id);
  exit(1); // Terminate with return status 1
}

int main(void){

}