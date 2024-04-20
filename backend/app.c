#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "add_task.h"
#include "read_task.h"
#include "delete_task.h"

// void updateTasks(Node** head); // Assuming this function is defined elsewhere
int main(int argc, char *argv[]) {
    Node* head = NULL;  // Start with an empty list
    int choice;

    printf("Welcome to the ToDo List Application!\n");

    do {
        printf("Select an option:\n");
        printf("0 - Add Task\n");
        printf("1 - Update Task\n");
        printf("2 - list Tasks \n");
        printf("5 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                getUserInput(&head);  // Handle user input for adding tasks
                break;
            case 1:
                updateTasks(&head);  // Update tasks, assuming function is defined
                break;
            case 2:
                printf("listing tasks. \n");
                read_tasks(head);      
            case 3:
                delete_task(&head);
            case 4:
                printf("exiting application\n");
                break;
             
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 2);


    return 0;  // Exit status of the program
}
