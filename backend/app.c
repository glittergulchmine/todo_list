#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TODOS 10
#define MAX_TODO_LENGTH 100

char todos[MAX_TODOS][MAX_TODO_LENGTH];
int count = 0;

void createTodo() {
    if (count >= MAX_TODOS) {
        printf("To-do list is full!\n");
        return;
    }
    printf("Enter a new to-do item: ");
    fgets(todos[count], MAX_TODO_LENGTH, stdin);
    todos[count][strcspn(todos[count], "\n")] = 0; // Remove newline character
    count++;
    printf("To-do item added successfully!\n");
}

void readTodos() {
    printf("To-do List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, todos[i]);
    }
}

void updateTodo() {
    int num;
    printf("Enter the number of the to-do item to update: ");
    scanf("%d", &num);
    getchar(); // Consume newline character

    if (num < 1 || num > count) {
        printf("Invalid to-do item number!\n");
        return;
    }

    printf("Enter the new to-do item: ");
    fgets(todos[num - 1], MAX_TODO_LENGTH, stdin);
    todos[num - 1][strcspn(todos[num - 1], "\n")] = 0; // Remove newline character
    printf("To-do item updated successfully!\n");
}

void deleteTodo() {
    int num;
    printf("Enter the number of the to-do item to delete: ");
    scanf("%d", &num);
    getchar(); // Consume newline character

    if (num < 1 || num > count) {
        printf("Invalid to-do item number!\n");
        return;
    }

    for (int i = num - 1; i < count - 1; i++) {
        strcpy(todos[i], todos[i + 1]);
    }
    count--;
    printf("To-do item deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nHi welcome to your personalized TO-DO list app. Please follow the instructions below:\n");
        printf("1. Create a to-do item\n");
        printf("2. Read all to-do items\n");
        printf("3. Update a to-do item\n");
        printf("4. Delete a to-do item\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                createTodo();
                break;
            case 2:
                readTodos();
                break;
            case 3:
                updateTodo();
                break;
            case 4:
                deleteTodo();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
