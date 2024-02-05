#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2
#define NUM_ITERATIONS 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_not_empty = PTHREAD_COND_INITIALIZER;

int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer
int produced_items = 0;
int consumed_items = 0;

void produce(int item) {
    buffer[count] = item;
    count++;
    produced_items++;
}

int consume() {
    int item = buffer[count - 1];
    count--;
    consumed_items++;
    return item;
}

void* producer(void* arg) {
    while (produced_items < NUM_ITERATIONS) {
        int item = rand() % 100; // Generate a random item
        pthread_mutex_lock(&mutex);

        // Wait if the buffer is full
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&buffer_not_full, &mutex);
        }

        produce(item);
        printf("Producer produces item: %d\n", item);

        // Signal consumers that the buffer is not empty
        pthread_cond_signal(&buffer_not_empty);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    while (consumed_items < NUM_ITERATIONS) {
        pthread_mutex_lock(&mutex);

        // Wait if the buffer is empty
        while (count == 0) {
            pthread_cond_wait(&buffer_not_empty, &mutex);
        }

        int item = consume();
        printf("Consumer consumes item: %d\n", item);

        // Signal producers that the buffer is not full
        pthread_cond_signal(&buffer_not_full);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS];
    long i;

    // Create producer threads
    for (i = 0; i < NUM_PRODUCERS; i++) {
        pthread_create(&producers[i], NULL, producer, (void*)i);
    }

    // Create consumer threads
    for (i = 0; i < NUM_CONSUMERS; i++) {
        pthread_create(&consumers[i], NULL, consumer, (void*)i);
    }

    // Join threads
    for (i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    for (i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }

    printf("Main thread exiting.\n");

    return 0;
}
