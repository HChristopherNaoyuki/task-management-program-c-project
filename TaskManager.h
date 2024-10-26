#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"

#define MAX_TASKS 100 /**< Maximum number of tasks in the manager */

/**
 * The TaskManager manages a list of tasks, providing operations to add, list,
 * complete, delete, search, and filter tasks.
 */
typedef struct 
{
    Task tasks[MAX_TASKS]; /**< Array of tasks */
    int taskCount;         /**< Current count of tasks */
} TaskManager;

/**
 * Initializes a new TaskManager with an empty task list.
 *
 * @param manager Pointer to the TaskManager to initialize
 */
void initTaskManager(TaskManager* manager);

/**
 * Adds a new task to the task list.
 *
 * @param manager Pointer to the TaskManager
 * @param description Description of the task
 * @param dueDate Due date of the task
 * @param priority Priority level of the task
 */
void addTask(TaskManager* manager, const char* description, struct tm dueDate, const char* priority);

/**
 * Lists all tasks in the task list.
 *
 * @param manager Pointer to the TaskManager
 */
void listTasks(const TaskManager* manager);

/**
 * Marks the task with the specified ID as completed.
 *
 * @param manager Pointer to the TaskManager
 * @param id ID of the task to complete
 */
void completeTask(TaskManager* manager, int id);

/**
 * Deletes the task with the specified ID from the task list.
 *
 * @param manager Pointer to the TaskManager
 * @param id ID of the task to delete
 */
void deleteTask(TaskManager* manager, int id);

/**
 * Searches for tasks that contain the specified keyword in their descriptions.
 *
 * @param manager Pointer to the TaskManager
 * @param keyword The keyword to search for
 */
void searchTasks(const TaskManager* manager, const char* keyword);

/**
 * Filters tasks based on the given criteria (priority, due date, or status) and value.
 *
 * @param manager Pointer to the TaskManager
 * @param criteria The criteria to filter by (priority, duedate, or status)
 * @param value The value for the filter criteria
 */
void filterTasks(const TaskManager* manager, const char* criteria, const char* value);

/**
 * Saves the current task list to a file specified by the filename.
 *
 * @param manager Pointer to the TaskManager
 * @param filename The name of the file to save tasks to
 */
void saveTasks(const TaskManager* manager, const char* filename);

/**
 * Loads tasks from a file specified by the filename into the task list.
 *
 * @param manager Pointer to the TaskManager
 * @param filename The name of the file to load tasks from
 */
void loadTasks(TaskManager* manager, const char* filename);

#endif // TASKMANAGER_H
