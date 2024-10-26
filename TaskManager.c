#include "TaskManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initTaskManager(TaskManager* manager) 
{
    manager->taskCount = 0;
}

void addTask(TaskManager* manager, const char* description, struct tm dueDate, const char* priority) 
{
    if (manager->taskCount < MAX_TASKS) 
    {
        initTask(&manager->tasks[manager->taskCount], manager->taskCount + 1, description, dueDate, priority);
        manager->taskCount++;
        printf("Task added successfully!\n");
    } 
    else 
    {
        printf("Task list is full!\n");
    }
}

void listTasks(const TaskManager* manager) 
{
    printf("Tasks:\n");
    for (int i = 0; i < manager->taskCount; i++) 
    {
        Task task = manager->tasks[i];
        printf("ID: %d, Description: %s, Due Date: %d-%02d-%02d, Priority: %s, Completed: %s\n",
               task.id, task.description, task.dueDate.tm_year + 1900, task.dueDate.tm_mon + 1, task.dueDate.tm_mday,
               task.completed ? "Yes" : "No");
    }
}

void completeTask(TaskManager* manager, int id) 
{
    for (int i = 0; i < manager->taskCount; i++) 
    {
        if (manager->tasks[i].id == id) 
        {
            markCompleted(&manager->tasks[i]);
            printf("Task marked as completed!\n");
            return;
        }
    }
    printf("Task not found!\n");
}

void deleteTask(TaskManager* manager, int id) 
{
    for (int i = 0; i < manager->taskCount; i++) 
    {
        if (manager->tasks[i].id == id) 
        {
            for (int j = i; j < manager->taskCount - 1; j++) 
            {
                manager->tasks[j] = manager->tasks[j + 1];
            }
            manager->taskCount--;
            printf("Task deleted successfully!\n");
            return;
        }
    }
    printf("Task not found!\n");
}

void searchTasks(const TaskManager* manager, const char* keyword) 
{
    printf("Search Results:\n");
    for (int i = 0; i < manager->taskCount; i++) 
    {
        if (strstr(manager->tasks[i].description, keyword) != NULL) 
        {
            Task task = manager->tasks[i];
            printf("ID: %d, Description: %s\n", task.id, task.description);
        }
    }
}

void filterTasks(const TaskManager* manager, const char* criteria, const char* value) 
{
    printf("Filtered Tasks:\n");
    for (int i = 0; i < manager->taskCount; i++) 
    {
        Task task = manager->tasks[i];
        if (strcmp(criteria, "priority") == 0 && strcmp(task.priority, value) == 0) 
        {
            printf("ID: %d, Description: %s\n", task.id, task.description);
        } 
        else if (strcmp(criteria, "duedate") == 0) 
        {
            struct tm dueDate = task.dueDate;
            char dateString[11];
            strftime(dateString, sizeof(dateString), "%Y-%m-%d", &dueDate);
            if (strcmp(dateString, value) == 0) 
            {
                printf("ID: %d, Description: %s\n", task.id, task.description);
            }
        } 
        else if (strcmp(criteria, "status") == 0 && (strcmp(value, "completed") == 0 && task.completed)) 
        {
            printf("ID: %d, Description: %s\n", task.id, task.description);
        }
    }
}

void saveTasks(const TaskManager* manager, const char* filename) 
{
    FILE* file = fopen(filename, "w");
    if (file) 
    {
        for (int i = 0; i < manager->taskCount; i++) 
        {
            Task task = manager->tasks[i];
            fprintf(file, "%d,%s,%d-%02d-%02d,%s,%d\n",
                    task.id, task.description, task.dueDate.tm_year + 1900,
                    task.dueDate.tm_mon + 1, task.dueDate.tm_mday,
                    task.priority, task.completed);
        }
        fclose(file);
        printf("Tasks saved to %s\n", filename);
    } 
    else 
    {
        printf("Error saving tasks to file!\n");
    }
}

void loadTasks(TaskManager* manager, const char* filename) 
{
    FILE* file = fopen(filename, "r");
    if (file) 
    {
        char line[512];
        while (fgets(line, sizeof(line), file) && manager->taskCount < MAX_TASKS) 
        {
            Task task;
            sscanf(line, "%d,%255[^,],%d-%d-%d,%9[^,],%d",
                   &task.id, task.description,
                   &task.dueDate.tm_year, &task.dueDate.tm_mon, &task.dueDate.tm_mday,
                   task.priority, &task.completed);
            task.dueDate.tm_year -= 1900; // Adjust year for tm struct
            task.dueDate.tm_mon -= 1;     // Adjust month for tm struct
            task.completed = (bool)task.completed;
            manager->tasks[manager->taskCount++] = task;
        }
        fclose(file);
        printf("Tasks loaded from %s\n", filename);
    } 
    else 
    {
        printf("Error loading tasks from file!\n");
    }
}
