// Adrion Thomas
// Assignment 1 - Producer Code
// Dr. Qiang Guan
// October 21st, 2024 

#include <iostream> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <cstdlib> 
#include "shared.hpp"

// semaphores and mutex 
sem_t empty, full; 
pthread_mutex_t mutex; 

// shared variables 
int table[max_items]; 
int in, out = 0; 

void* producer(void* arg){
    while(true){
        int item = rand() % 100; 

        sem_wait(&empty); 
        pthread_mutex_lock(&mutex); 

        table[in] = item; 
        std::cout << "Producer has produced an item : " << item << std::endl; 
        in = (in + 1) % max_items; 

        pthread_mutex_unlock(&mutex); 
        sem_post(&full); 

        sleep(1); 
    }
    return nullptr; 
}


int main() { 
    pthread_t prodThread; 

    sem_init(&empty, 0, max_items); 
    sem_init(&full, 0, 0); 
    pthread_mutex_init(&mutex, nullptr); 

    pthread_create(&prodThread, nullptr, producer, nullptr); 
    pthread_join(prodThread, nullptr); 

    pthread_mutex_destroy(&mutex); 
    sem_destroy(&empty);    
    sem_destroy(&full); 

    return 0; 

}