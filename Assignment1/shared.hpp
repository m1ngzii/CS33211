// Adrion Thomas
// Assignment 1 -  Header File 
// Dr. Qiang Guan
// October 21st, 2024 


#ifndef SHARED_H
#define SHARED_H

#include <pthread.h> 
#include <semaphore.h> 

#define maxItems 2 

// shared variables 
struct sharedData{ 
    sem_t *empty;
    sem_t *full; 
    sem_t *mutex; 
    int table[maxItems];
    int in, out; 
};

const char* shmPath = "/unique_Memory"; 




#endif 
