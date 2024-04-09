
#include "stdio.h"
#include "stdlib.h"

#include "structure.h"


Node * createNode(const char* date,const char*time, const char *taskDescription){

    Node * newNode=(Node*)malloc(sizeof(Node));  // size of Node
    if(newNode){
        strncpy(newNode->taskData.date,date,23); // giving the max size for date
        newNode->taskData.date[23]="\0";    //terminating the null character
        strncpy(newNode->taskData.time,time,23); // giving the max size for date
        newNode->taskData.time[23]="\0";    //terminating the null character
        strncpy(newNode->taskData.task,taskDescription,255); // giving the max size for date
        newNode->taskData.date[23]="\0";    //terminating the null character
        newNode->next=NULL;
    }
    // else{
    //     // calls the error.c function
    // }

    return newNode;
}
void add_tasks(Node*head, char*date,char*time, char*taskDescription){

    return 0;
}
void get_user_input(){


return 0;

}
