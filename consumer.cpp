// Adrion Thomas
// Assignment 1 - Consumer Code
// Dr. Qiang Guan
// October 21st, 2024 

#include <iostream> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include "shared.hpp" 

// semaphores and mutex 
sem_t empty, full; 
pthread_mutex_t mutex; 

// shared variables 
int table[max_items]; 
int in = 0; 
int out = 0; 


void* consumer(void* arg){
    while(true){
            while(in == out){
            sem_wait(&full);
            pthread_mutex_lock(&mutex); 
            }

        int item = table[out]; 
        std::cout << "Consumer has consumed an item : " << item << std::endl; 
        out = (out + 1) % max_items; 

        pthread_mutex_unlock(&mutex); 
        sem_post(&empty); 

        sleep(1); 
    }

}

int main(){
    pthread_t consThread; 

    pthread_create(&consThread, nullptr, consumer, nullptr); 

    pthread_join(consThread,nullptr); 

    pthread_mutex_destroy(&mutex); 
    sem_destroy(&empty);    
    sem_destroy(&full); 

    return 0; 
}