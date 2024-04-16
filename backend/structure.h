// structure.h

#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct {
    char date[24];  // Date of the task ("YYYY-MM-DD")
    char time[24];  // Time of the task ("HH:MM")
    char task[256]; // Task description
} MyTask;

typedef struct Node {
    MyTask taskData;   // Task data
    struct Node* next; // Pointer to the next node
} Node;

// Function declarations
Node* createNode(const char* date, const char* time, const char* taskDescription);
void addTask(Node** head, const char* date, const char* time, const char* taskDescription);
void printTasks(const Node* head);
void freeList(Node** head);

#endif // STRUCTURE_H
