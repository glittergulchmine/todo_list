// structure.h

#ifndef STRUCTURE_H // Check if STRUCTURE_H is not defined
#define STRUCTURE_H // Define STRUCTURE_H

// Structure to hold task information
typedef struct {
    char date[24];  // Date of the task in formatted string
    char time[24];  // Time of the task in formatted string
    char task[256]; // Task description
} MyTask;

// Node structure for a linked list of tasks
typedef struct Node {
    MyTask taskData;   // Task data
    struct Node* next; // Pointer to next node
} Node;

#endif // STRUCTURE_H
