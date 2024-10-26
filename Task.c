#include "Task.h"
#include <string.h>

void initTask(Task* task, int id, const char* description, struct tm dueDate, const char* priority) 
{
    task->id = id;
    strncpy(task->description, description, sizeof(task->description) - 1);
    task->description[sizeof(task->description) - 1] = '\0';
    task->dueDate = dueDate;
    strncpy(task->priority, priority, sizeof(task->priority) - 1);
    task->priority[sizeof(task->priority) - 1] = '\0';
    task->completed = false;
}

void markCompleted(Task* task) 
{
    task->completed = true;
}

const char* getDescription(const Task* task) 
{
    return task->description;
}

struct tm getDueDate(const Task* task) 
{
    return task->dueDate;
}

const char* getPriority(const Task* task) 
{
    return task->priority;
}

bool isCompleted(const Task* task) 
{
    return task->completed;
}
