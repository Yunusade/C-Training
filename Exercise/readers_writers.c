#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t reader_condition = PTHREAD_COND_INITIALIZER, writer_condition = PTHREAD_COND_INITIALIZER;

int readers_count = 0;
int data = 0;

void* reader(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        // Wait if there is a writer writing
        while (readers_count == -1) {
            pthread_cond_wait(&reader_condition, &mutex);
        }

        readers_count++;
        pthread_mutex_unlock(&mutex);

        // Read from the database
        printf("Reader %ld reads data: %d\n", (long)arg, data);

        pthread_mutex_lock(&mutex);
        readers_count--;

        // Signal the writer if all readers have finished reading
        if (readers_count == 0) {
            pthread_cond_signal(&writer_condition);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void* writer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        // Wait if there is a reader or writer
        while (readers_count != 0) {
            pthread_cond_wait(&writer_condition, &mutex);
        }

        // Set readers_count to -1 to block readers
        readers_count = -1;
        pthread_mutex_unlock(&mutex);

        // Write to the database
        data++;
        printf("Writer %ld writes data: %d\n", (long)arg, data);

        pthread_mutex_lock(&mutex);

        // Reset readers_count to allow readers
        readers_count = 0;

        // Signal waiting readers
        pthread_cond_broadcast(&reader_condition);

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    long i;

    // Create reader threads
    for (i = 0; i < NUM_READERS; i++) {
        pthread_create(&readers[i], NULL, reader, (void*)i);
    }

    // Create writer threads
    for (i = 0; i < NUM_WRITERS; i++) {
        pthread_create(&writers[i], NULL, writer, (void*)i);
    }

    // Join threads (this will never be reached in this example)
    for (i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    return 0;
}
