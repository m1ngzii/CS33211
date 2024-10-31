# PRODUCER-CONSUMER ASSIGNMENT - OPERATING SYSTEMS 

# Overview  
My name is Adrion Thomas and in Assignment 1 of Operating Systems, we had to make a producer that produces a max of 2 items whilst an consumer consumes the items the producer outputs. This assignment utlizies shared memory between the two programs, in my case, we used semaphores to implement a critical section to ensure data consistency. 

The two programs are implemented in C++ and both use a shared header file (shared.hpp). 

# How It Works



# Compilation Instructions 
g++ producer.cpp -o producer -lpthread
g++ consumer.cpp -o consumer -lpthread
 ./producer & ./consumer &  

