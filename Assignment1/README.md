# PRODUCER-CONSUMER ASSIGNMENT - OPERATING SYSTEMS 

# Overview  
My name is Adrion Thomas and in Assignment 1 of Operating Systems, we had to make a producer that produces a max of 2 items while an consumer consumes the items the producer outputs. This assignment utlizies shared memory between the two programs; In my case, we used semaphores to implement a critical section to ensure data consistency and prevent race conditions. 

Both programs are implemented in C++ and use a shared header file (shared.hpp). 

# How It Works / Documentation
In our header file, we have 3 semaphores : empty, full, and a mutex. Empty and full are used for buffer access to the producer and consumer, while the mutex semaphore protects the critical section, ensuring one program is accessing the buffer. Each program iterates the producer-consumer interaction five times.

**Producer** 
- Waits for a slot to be available in the buffer
- Locks the critical section
- Produces an item
- Unlocks the critical section
- Signals that a slot has been filled.

**Consumer** 
- Waits until there is a filled slot
- Locks critical section
- Consumes an item
- Unlocks the critical section
- Signals that the slot is now empty

# Example Output 
Produced : 0 
Consumed : 0 
Produced : 1
Consumed : 1
Produced : 2 
Consumed : 2
Produced : 3
Consumed : 3 
Produced : 4 
Consumed : 4

or 
Produced : 0 
Produced : 1 

Consumed : 0 
Consumed 1 


# Compilation Instructions 
g++ producer.cpp -o producer -lpthread 

g++ consumer.cpp -o consumer -lpthread


 ./producer & ./consumer &  

