#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NTHREADS 12
#define ITERATIONS 100000

int cont = 0;

void* threadFunction(void* arg) {
    int thread_id = *((int*)arg);

    for (int i = 0; i < ITERATIONS; ++i) {
        printf("I'm thread %d and my value is %d\n", thread_id, cont);
        cont++;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NTHREADS];
    int thread_args[NTHREADS];

    for (int i = 0; i < NTHREADS; ++i) {
        thread_args[i] = i + 1;

        if (pthread_create(&threads[i], NULL, threadFunction, (void*)&thread_args[i]) != 0) {
            perror("pthread_create error");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NTHREADS; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join error");
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads have finished.\n");

    return 0;
}
