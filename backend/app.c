#include<stdio.h>

// Define a structure named MyTask to represent a task in a ToDoList.
// This structure includes the date, time, and task description.
typedef struct {
    char date[24];  // Holds the date of the task. The size is 24 characters to ensure it can include a formatted date string.
    char time[24];  // Holds the time of the task. Similar to date, it has 24 characters to accommodate different time formats.
    char task[256]; // Holds the task description. The array size of 256 characters allows for a detailed description of the task.
} MyTask;

typedef struct Node{
    MyTask.TaskData;
    Node* next;
    
}Node;

int main() {
    // The main function of the program. Execution starts here.

    // (Here, you would typically include code to create instances of MyTask,
    // manipulate them, or perform other operations related to your ToDoList application.)

    return 0; // Indicates that the program finished successfully.
}
