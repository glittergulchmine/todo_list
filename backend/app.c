#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "add_task.h"

int main(int argc, char *argv[]) {
    Node* head = NULL;  // Initialize the linked list head to NULL

    printf("Welcome to the ToDo List Application!\n");
    getUserInput(&head);  // Handle user input for adding tasks

    // Optional: Additional code to manipulate or display task
    printf("Exiting the application. Goodbye!\n");

    return 0;  // Exit status of the program
}
