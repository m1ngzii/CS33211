// Adrion Thomas
// Assignment 1 - Producer Code
// Dr. Qiang Guan
// October 21st, 2024 

#include <iostream> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <cstdlib> 
#include <sys/mman.h>
#include "shared.hpp"

int main(int argc, char* argv[]){

    const char* shmPath = "/shMemPath"; 
    // creating/open shared memory .. size = 0 bytes 
    int shmShared = shm_open(shmPath, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR ); 
    if(shmShared == -1){ 
    std::cerr << "Error handling memory, try again!" << std::endl; 
    return 1; 
    }


    // ftruncate ensures that the shared memory will not remain stagnant
    // at 0, allowing the shared mem. object to resize to the amount needed.
    if(ftruncate(shmShared, sizeof(sharedData)) == -1){ 
        std::cerr << "Error : ftruncate() has failed, try again." << std::endl; 
        close(shmShared); 
        return 1; 
    } else {
        ftruncate(shmShared, sizeof(sharedData)); 
    }
    
    // mapping memory
    sharedData *producer; 
    producer = static_cast<sharedData*>(mmap(0, sizeof(sharedData),PROT_READ | PROT_WRITE, MAP_SHARED, shmShared, 0)); 
    // static_cast returns the value of mmap() to sharedData* and lets producer treat the mapped mem. as an instance
    // of sharedData allowing the members to have access to it. 
    // each parameter's meaning : 0 = starting address for mapping
    // sizeof(sharedData) = establishes the length of the mapping in bytes (ensures that the entire structure is mapped)
    // PROT_READ | PROT_WRITE are protection flags - specifies that mapped meory is readable + writable by process
    // MAP_SHARED = updates to the mapped mem. will be available for other processes that map the same shared mem. region
    // shmShared = shared mem. object
    // 0 = offset within the mem. object where the mem. starts. 

    sem_init(&(producer->empty), 1, maxItems); // ensuring all empty slots 
    sem_init(&(producer->full), 1, 0); // no filled slots
    sem_init(&(producer->mutex),1,1); 

    for(int i = 0; i < 5; ++i){
        sem_wait(&(producer->empty)); 
        sem_wait(&(producer->mutex)); 

        int producerVal = rand() % 100 + 1; 
        producer->table[i % maxItems] = producerVal;
        std::cout << "Produced : " << producerVal << std::endl; 

        sem_post(&(producer->full)); 
        sem_post(&(producer-> mutex)); 
        sleep(1); 


    }

    shm_unlink("/shMemPath"); 
    return 0; 
}