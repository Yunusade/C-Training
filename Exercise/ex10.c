#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void child_process() {
  pid_t child_pid = getpid();
  pid_t parent_pid = getppid();
  printf("I'm %d, son of process %d\n", child_pid, parent_pid);
}

void parent_process(pid_t child_pid) {
    pid_t parent_pid = getpid();
    printf("I'm the father. My Son is: %d\n", child_pid);
}

int main() {
    pid_t pid = fork(); 
    if (pid == 0) {
      // Child process
      child_process();
    } else {
      // Parent process
      parent_process(pid);
    }

    return 0;
}
