#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define BUFFER_SIZE 5
sem_t empty, full, mutex;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
void *producer(void *arg) {
int item;
for (int i = 0; i<10; ++i) {
item = rand(); 
sem_wait(&empty);
sem_wait(&mutex);
buffer[in] = item;
in = (in + 1) % BUFFER_SIZE;
sem_post(&mutex);
sem_post(&full);
printf("Produced item %d\n", item);
}
pthread_exit(NULL);
}
void *consumer(void *arg) {
int item;
for (int i = 0; i<10; ++i) {
sem_wait(&full);
sem_wait(&mutex);
item = buffer[out];
out = (out + 1) % BUFFER_SIZE;
sem_post(&mutex);
sem_post(&empty);
printf("Consumed item %d\n", item);
}
pthread_exit(NULL);
}
int main() {
sem_init(&empty, 0, BUFFER_SIZE);
sem_init(&full, 0, 0);
sem_init(&mutex, 0, 1);
pthread_t producer_thread, consumer_thread;
pthread_create(&producer_thread, NULL, producer, NULL);
pthread_create(&consumer_thread, NULL, consumer, NULL);
pthread_join(producer_thread, NULL);
pthread_join(consumer_thread, NULL);
sem_destroy(&empty);
sem_destroy(&full);
sem_destroy(&mutex);
return 0;
}
