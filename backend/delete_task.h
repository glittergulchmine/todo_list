#include <stdio.h>
#include <stdlib.h>
#include "structure.h"


void delete_task(Node **head) {
    int charId;
    Node *temp = *head, *prev = NULL;

    // First, display the tasks to the user
    printf("Below are your tasks:\n");
    read_tasks(*head);  // Assuming read_tasks takes Node* and not Node**

    // Get the task number to delete
    printf("\nEnter a task number to delete: ");
    scanf("%d", &charId);

    // Find the task with the given charId
    while (temp != NULL && temp->taskData.charId != charId) {
        prev = temp;
        temp = temp->next;
    }

    // If the task is not found
    if (temp == NULL) {
        printf("Task with ID %d not found.\n", charId);
        return;
    }

    // If the task to delete is the head of the list
    if (prev == NULL) {
        *head = temp->next;  // Update the head pointer to the next node
    } else {
        prev->next = temp->next;  // Bypass the node to delete it
    }

    // Free the memory allocated for the deleted node
    free(temp);
    
    printf("Task with ID %d has been deleted.\n", charId);
    read_tasks(*head);
}

