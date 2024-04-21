#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct {
    int charId;
    char date[24];
    char time[24];
    char task[256];
} MyTask;

typedef struct Node {
    MyTask taskData;
    struct Node* next;
} Node;

// Function declarations
Node* createNode(int charId, const char* date, const char* time, const char* taskDescription);
void addTask(Node** head, const char* date, const char* time, const char* taskDescription);
void read_tasks(Node* head);
void delete_task(Node** head);

#endif // STRUCTURE_H