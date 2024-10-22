// Adrion Thomas
// Assignment 1 -  Header File 
// Dr. Qiang Guan
// October 21st, 2024 


#ifndef shared_h 
#define shared_h 

#include <pthread.h> 
#include <semaphore.h> 

#define max_items 2 

// shared variables 
extern int table[max_items]; 
extern int in, out; 

// semaphores and mutex 
extern sem_t empty; 
extern sem_t full; 
extern pthread_mutex_t mutex; 




#endif 