# BANKER'S ALGORITHM - Operating Systems 

# Overview  
My name is Adrion Thomas and in this project for Operating Systems, we implemented the Banker's Algorithm to determine wheter the system is in a safe state. The Banker's Algorithm is a resource allocation and deadlock avoidance algorithm that ensures resources are allocated safely to processes without leading to a deadlock.

The project uses C++ and reads input from a file ('input.txt'). The algorithm computes the Need matrix, checks available resources, and gets a safe sequence if the system is in a safe state. 

# How It Works / Documentation
The Banker's Algorithm is implemented : 

**Input** 
- Processes : 5 processes (P0-P4)
- Resources : 3 types of resources (A-C) with availability specified in the input.
- Allocation : Current allocation of resources to processes
- Max : Max resource demand of each process 

The program reads the following data from an input file : 
1. Process IDs
2. Available resources
3. Maximum demand matrix
4. Allocation matrix

**Output** 
- If the system is safe, the program output the safe sequence
- If the system is unsafe, no sequence will be outputted.

** Example Output** 
System is in a safe state.
Safe sequence is: P1 P3 P4 P0 P2


# Compilation Instructions 
g++ banker.cpp -o bankers_algorithm
./bankers_algorithm

