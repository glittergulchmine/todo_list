#include "stdio.h"
#include "stdlib.h"
#include "string.h" // Include for string functions
#include "structure.h" // Ensure this includes the definitions of Node and related structures

void read_tasks(Node* head) {
    Node* temp = head; // Use a single pointer for traversal

    // Traverse the linked list
    while (temp != NULL) {
        // Print the date, time, and task description for each task
        printf("Task number: %d, Date: %s, Time: %s, Task: %s\n", 
               temp->taskData.charId ,
               temp->taskData.date, 
               temp->taskData.time, 
               temp->taskData.task);
        temp = temp->next; // Move to the next node
    }
}
