// Adrion Thomas
// Banker's Algorithm Project
// Dr. Qiang Guan
// November 19th, 2024

#include <iostream>
#include <fstream>
using namespace std;

const int p = 5; // num. of processes
const int r = 3; // num. of resources

// function to calculate the need matrix from max and allocation
void calculateNeed(int need[p][r], int max[p][r], int alloc[p][r]) {
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

// func. to check if the system is in safe state 
bool isInSafeState(int processes[], int available[], int max[][r], int alloc[][r]) {
    int need[p][r]; // need matrix to track the remaining resource req. for each process
    calculateNeed(need, max, alloc); // calc. need matrix 

    bool finish[p] = {0}; // track whether a process has completed execution (all are initialzed as not finished)
    int safeSequence[p]; // storing the save sequence 
    int work[r]; // temp. array to see available resources during execution

    // setting work array to the available resources 
    for (int i = 0; i < r; i++) {
        work[i] = available[i];
    }

    int count = 0; // index counter for processes 
    while (count < p) {
        bool found = false; // track if a process was executed 

        for (int pp = 0; pp < p; pp++) {
            if (!finish[pp]) { // if a process is not finished if its need is less than the work
                int j;
                for (j = 0; j < r; j++) 
                    if (need[pp][j] > work[j])
                        break; // if need > work for any resource, break out of this loop

                // if all resources need by the process can be allocated 
                if (j == r) {
                    for (int k = 0; k < r; k++) // add the process' allocated resources to work 
                        work[k] += alloc[pp][k];

                    // add process to the safe sequence 
                    safeSequence[count++] = pp;

                    // mark process as finished 
                    finish[pp] = true;
                    found = true; // process was executed 
                }
            }
        }

        // if no process could be executed, it is in an unsafe state 
        if (!found) {
            cout << "System is not in a safe state" << endl;
            return false;
        }
    }
    
    // if processes can finishm the system is in a safe state 
    cout << "System is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < p; i++){
        cout << "P" << safeSequence[i] << " ";
    }   
    cout << endl;
    return true;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    int processes[p]; // process ids
    int available[r]; // available instances of the resources 
    int max[p][r]; // max amnt of reosurces req. by each process 
    int alloc[p][r]; // allocated resources to each process 

    for (int i = 0; i < p; i++) { 
        inputFile >> processes[i];
    }

    for (int i = 0; i < r; i++) { 
        inputFile >> available[i];
    }

    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            inputFile >> max[i][j];

    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            inputFile >> alloc[i][j];

    inputFile.close();

    isInSafeState(processes, available, max, alloc); // check if system is in a safe state

    return 0;
}
