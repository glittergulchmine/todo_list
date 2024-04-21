#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

void update_task(Node **head) {
    int charId;
    
    printf("Enter task charID to update: ");
    scanf("%d", &charId);  // Get the charID from user input

    Node* current = *head;
    while (current != NULL && current->taskData.charId != charId) {
        current = current->next;  // Traverse the list to find the task
    }
    if (current == NULL) {
        printf("Task with charID %d not found.\n", charId);
        return;  // If no task is found, exit the function
    }
    // If the task is found, prompt the user for new details
    printf("Updating Task ID %d\n", charId);
    printf("Enter new date (YYYY-MM-DD): ");
    scanf("%s", current->taskData.date);  // Update the date

    printf("Enter new time (HH:MM): ");
    scanf("%s", current->taskData.time);  // Update the time
    printf("Enter new task description: ");
    scanf(" %[^\n]", current->taskData.task);  // Update the task description, handling spaces

    printf("Task updated successfully!\n");
}
