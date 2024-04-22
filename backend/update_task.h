#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

void update_task(Node **head) {
    int charId;

    // First, display the tasks to the user
    printf("Below are your tasks:\n");
    read_tasks(*head);
    
    printf("\nEnter the task number to update: ");
    scanf("%d", &charId);  // Get the charID from user input

    Node* current = *head;
    while (current != NULL && current->taskData.charId != charId) {
        current = current->next;  // Traverse the list to find the task
    }
    if (current == NULL) {
        printf("Task with number %d not found.\n", charId);
        return;  // If no task is found, exit the function
    }
    // If the task is found, prompt the user for new details
    printf("\n\tUpdating Task ID %d\n\n", charId);
    printf("Enter new date (YYYY-MM-DD): ");
    scanf("%s", current->taskData.date);  // Update the date
    printf("Enter new time (HH:MM): ");
    scanf("%s", current->taskData.time);  // Update the time
    printf("Enter new task description: ");
    scanf(" %[^\n]", current->taskData.task);  // Update the task description, handling spaces

    printf("\n\tTask updated successfully!\n");
}
