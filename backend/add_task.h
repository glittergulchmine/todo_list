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
    //int *ptr = &charId;
    Node* current = *head;
    Node* temp = *head;

    if (current != NULL) {

        while (temp != NULL){

            if(charId != temp->taskData.charId)
            {
                break;
            }
            charId++;
            temp = temp->next;
        }

        while (current->next != NULL){
            current = current->next;
        }
    }

    Node* newNode = createNode(charId, date, time,task);
    if (newNode == NULL) {
        return; // Return early if failed to create a new node
    }
    if(current == NULL){ // Insert at the head
        newNode->next = *head;
        *head = newNode;
    }
    else{ //Insert at end
        newNode->next = NULL;
        current->next = newNode;
    }
}

void getUserInput(Node** head) {
    int choice;

    do {
        printf("To add a task to your list, press 1.\nTo return to the menu, press 0: ");
        scanf("%d", &choice); // Read user input

        if (choice == 1) {
            char date[25], time[25], task[256];

            printf("\nEnter the date (YYYY-MM-DD): ");
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

            printf("\n\tTask has been added.");
        } else if (choice == 0) {
            break; // Exit the loop and function
        } else {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 1);
}
