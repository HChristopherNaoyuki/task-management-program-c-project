#ifndef TASK_H
#define TASK_H

#include <stdbool.h>
#include <time.h>

/**
 * Represents a task with a description, due date, priority, and completion status.
 */
typedef struct 
{
    int id;                     /**< Unique identifier for the task */
    char description[256];      /**< Description of the task */
    struct tm dueDate;         /**< Due date of the task */
    char priority[10];          /**< Priority level of the task (High, Medium, Low) */
    bool completed;             /**< Completion status of the task */
} Task;

/**
 * Initializes a new task with the given description, due date, and priority.
 *
 * @param task Pointer to the task to initialize
 * @param id Unique ID for the task
 * @param description The description of the task
 * @param dueDate The due date of the task
 * @param priority The priority level of the task
 */
void initTask(Task* task, int id, const char* description, struct tm dueDate, const char* priority);

/**
 * Marks the task as completed.
 *
 * @param task Pointer to the task to complete
 */
void markCompleted(Task* task);

/**
 * Returns the task's description.
 *
 * @param task Pointer to the task
 * @return Description of the task
 */
const char* getDescription(const Task* task);

/**
 * Returns the task's due date.
 *
 * @param task Pointer to the task
 * @return Due date of the task
 */
struct tm getDueDate(const Task* task);

/**
 * Returns the task's priority.
 *
 * @param task Pointer to the task
 * @return Priority of the task
 */
const char* getPriority(const Task* task);

/**
 * Returns the task's completion status.
 *
 * @param task Pointer to the task
 * @return True if the task is completed, false otherwise
 */
bool isCompleted(const Task* task);

#endif // TASK_H
