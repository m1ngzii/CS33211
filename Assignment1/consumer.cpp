// Adrion Thomas
// Assignment 1 - Consumer Code
// Dr. Qiang Guan
// October 21st, 2024 

#include <iostream> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <cstdlib> 
#include <sys/mman.h>
#include "shared.hpp"

int main(int argc, char *argv[]){

    int shmShared = shm_open(shmPath,O_CREAT | O_RDWR, 0666); 
    if(shmShared == -1){ 
    std::cerr << "Error handling memory, try again!" << std::endl; 
    return 1; 
    }

    
    sharedData *consumer; 
    consumer = (sharedData*)(mmap(0, sizeof(sharedData),PROT_READ | PROT_WRITE, MAP_SHARED, shmShared, 0));
    if(consumer == MAP_FAILED){
        std::cerr << "ERROR IN MAPPING SHARED MEMORY." << std::endl; 
        close(shmShared);
        return 1; 
    }



    for(int i = 0; i < 5; ++i){
        sem_wait(&(consumer->full)); 
        sem_wait(&(consumer->mutex)); 

        int consumerVal = consumer->table[i % maxItems]; 
        std::cout << "Consumed : " << consumerVal << std::endl; 

        sem_post(&(consumer->empty)); 
        sem_post(&(consumer->mutex)); 

        sleep(1); 
    }

    if (munmap(consumer, sizeof(sharedData)) == -1) {
        std::cerr << "Error unmapping shared memory: " << strerror(errno) << std::endl;
    }
    shm_unlink("/shMemPath"); 
    return 0; 
}
