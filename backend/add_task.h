// Assume including necessary headers and the "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "ctype.h"


Node* createNode(int charId, const char* date, const char* time, const char* task) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return NULL;
    }

    newNode->taskData.charId = charId;
    strncpy(newNode->taskData.date, date, 23);
    newNode->taskData.date[23] = '\0';
    strncpy(newNode->taskData.time, time, 23);
    newNode->taskData.time[23] = '\0';
    strncpy(newNode->taskData.task, task, 255);
    newNode->taskData.task[255] = '\0';
    newNode->next = NULL;

    return newNode;
}

void addTask(Node** head, const char* date, const char* time, const char* task) {
    int charId = 0;
    Node* current = *head;

    if (current != NULL) {
        charId += 1;
        while (current->next != NULL) {
            current = current->next;
            charId++;
        }
    }

    Node* newNode = createNode(charId, date, time,task);
    if (newNode == NULL) {
        return; // Return early if failed to create a new node
    }

    newNode->next = *head; // Insert at the head for simplicity
    *head = newNode;
}

void getUserInput(Node** head) {
    int choice;

    do {
        printf("To add tasks to your app, press 0.\nTo exit, press 1: ");
        scanf("%d", &choice); // Read user input

        if (choice == 0) {
            char date[25], time[25], task[256];

            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", date); // Read date
            getchar(); // Consume the newline

            printf("Enter the time (HH:MM): ");
            scanf("%s", time); // Read time
            getchar(); // Consume the newline

            printf("Enter the task: ");
            fgets(task, sizeof(task), stdin);
            task[strcspn(task, "\n")] = 0; // Remove newline character

            if (isValidDate(date) && isValidTime(time) && strlen(task) > 0) {
                addTask(head, date, time, task);
            } else {
                printf("Invalid input. Please ensure the date, time, and task description are correct.\n");
            }
        } else if (choice == 1) {
            printf("Goodbye!\n");
            break; // Exit the loop and function
        } else {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 1);
}
