Todo List Application Documentation

Introduction

The Todo List application is a straightforward program written in C. It's designed to efficiently store user tasks, leveraging structures and linked lists for data management. Memory for each task is dynamically allocated, ensuring optimal use of resources. Tasks can be removed either by user action or automatically when they are past their due date, at which point the allocated memory is also freed \*

Folder structure:
.git
-backend
add_task.c // for adding task
app.c // runs the main application
delete_task.c // for deleting task
error.c // for handling all the errors
structure.h // for the frame of the todo list
update_task.c // for updating task

....

//Important information
Main Compilation File: app.c serves as the core of the application, compiling all necessary header files. This centralization simplifies the build process.

Modular Design: The project is segmented into various files. This modular approach enhances readability, simplifies debugging, and streamlines code maintenance. Each component can be developed and tested independently, contributing to a more robust application.
