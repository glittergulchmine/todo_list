#include "stdio.h"
#include "stdlib.h"
#include "structure.h"

//Function to print all tasks in link list
int printNodes(struct Node* head, char date[], char time[], char taskTitle[], char taskDescription[])
{
    int counter = 0;
    struct Node* current = head;

    //Loop to print each node in link list
    while(current != NULL)
    {
        counter++;

        printf("\n%d: %s, %s\n", counter, date, time);    //Prints the number of the node, date and time
        puts(taskTitle);    //Prints the title of the task
        printf("\n");
        puts(taskDescription);  //Prints the descripton of the task
        printf("\n\n");

        current = current->next;
    }
    return counter;
}

//Main function to delete task
void delete_task(struct Node* head, char date[], char time[], char taskTitle[], char taskDescription[])
{
    int choice = 0, maxNodes;
    struct Node* current = head;
    struct Node* previous = head;

    //Ask user which node they would like to delete
    maxNodes = printNodes(head, date, time, taskTitle, taskDescription);
    printf("If you don't want to delete any node, enter 0\n");
    printf("Please enter the corresponding number for the task you would like to update: ");
    scanf("%d", &choice);

    //Make sure user enters an actual node
    while((choice > maxNodes) || (choice < 0))
    {
        printf("That was not an option, please enter one of the listed numbers (0-%d): ", maxNodes);
        scanf("%d", &choice);
    }

    //Logic to travers to the correct node
    if(choice == 0)//User does not want to delete node
    {
        printf("\nReturning to menu\n");
    }
    else if(choice == 1)//User wants to delete first node
    {
        head = head->next;
    }
    else
    {
        for(int i = 1; i < choice; i++)//Traverses to correct node
        {
            previous = current;
            current = current->next;
        }
        if(current->next == '\0')//User wants to delete last node
        {
            previous->next = '\0';
        }
        else    //User wants to delete node in the middle
        {
            previous->next = previous->next->next;
        }
    }
}

// this section works on deleting task on the  todo list
// please read the documentation section for more information
