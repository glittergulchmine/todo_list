#include "stdio.h"
#include "stdlib.h"
#include "string.h" // Include for string functions

#include "structure.h"

Node* createNode(const char* date, const char* time, const char* taskDescription) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return NULL;
    }

    strncpy(newNode->taskData.date, date, 23);
    newNode->taskData.date[23] = '\0';

    strncpy(newNode->taskData.time, time, 23);
    newNode->taskData.time[23] = '\0';

    strncpy(newNode->taskData.task, taskDescription, 255);
    newNode->taskData.task[255] = '\0';

    newNode->next = NULL;

    return newNode;
}
void addTask(Node** head, const char* date, const char* time, const char* taskDescription) {
    Node* newNode = createNode(date, time, taskDescription);
    if (newNode == NULL) {
        return;  // Return early if failed to create a new node
    }

    newNode->next = *head;
    *head = newNode;
}

void getUserInput(Node** head) {
    int choice;
    printf("Hello, welcome to your personal TODO list app\n");
    printf("\nWhat can I help you with today?\n");

    do {
     
        printf("To add tasks to your app, press 0.\nTo exit, press 1: ");
        scanf("%d", &choice); // Read user input

        if (choice == 0) {
            char date[25], time[25], task[256];

            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", date); // Simple input without validation

            printf("Enter the time (HH:MM): ");
            scanf("%s", time); // Simple input without validation

            printf("Enter the task description: ");
            scanf(" %[^\n]s", task); // Read a line of text including spaces

            addTask(head, date, time, task); // Add the task to the list
        } else if (choice == 1) {
            printf("Goodbye!\n");
            break; // Exit the loop and function
        } else {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 1);
}