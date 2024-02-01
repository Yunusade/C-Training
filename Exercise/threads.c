#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* myturn( void * arg) {
  int *iptr = (int *) arg;
  for(int i=0; i < 8; i++)
  {
    sleep(1);
    printf("My Turn!\n");
  }

  return NULL;
}

void yourturn() {
  for(int i=0; i < 3; i++)
  {
    sleep(2);
    printf("Your Turn!\n");
  }
}

int main()
{
  pthread_t newthread;

  pthread_create(&newthread, NULL, myturn, NULL);
  yourturn();

  // Wait until the thread is done before we exit.
  pthread_join(&newthread, NULL);
}