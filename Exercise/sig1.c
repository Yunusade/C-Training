#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig) {
  printf("Received sig %d, from my parent %d\n", sig, getppid());
  exit(1);
}

int main() {
  pid_t child1, child2, child3;

  signal(SIGUSR1, handle_signal);

  child1 = fork();
  if (child1 == 0) {
    printf("Child 1: Message from child 1\n");
    exit(0);
  }

  child2 = fork();
  if (child2 == 0) {
    while (1) {
      printf("Child 2: In an infinite loop\n");
      sleep(1);
    }
  }

  child3 = fork();
  if (child3 == 0) {
    while (1) {
      printf("Child 3: In an infinite loop\n");
      sleep(1);
    }
  }

  sleep(6);

  kill(child1, SIGUSR1);
  kill(child2, SIGUSR1);
  kill(child3, SIGUSR1);
  return 0;
}
