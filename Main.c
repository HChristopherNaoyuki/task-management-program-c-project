#include <stdio.h>
#include <time.h>
#include "TaskManager.h"

/**
 * Displays the main menu options for the Task Manager.
 */
void printMenu() 
{
    printf("Task Manager\n");
    printf("1. Add Task\n");
    printf("2. List Tasks\n");
    printf("3. Complete Task\n");
    printf("4. Delete Task\n");
    printf("5. Search Tasks\n");
    printf("6. Filter Tasks\n");
    printf("7. Save Tasks\n");
    printf("8. Load Tasks\n");
    printf("9. Exit\n");
    printf("Select an option: ");
}

int main() 
{
    TaskManager manager;
    initTaskManager(&manager);
    
    while (1) 
    {
        printMenu();
        int choice;
        scanf("%d", &choice);
        
        if (choice == 9) 
        {
            break;
        }
        
        switch (choice) 
        {
            case 1: 
            {
                char description[256], priority[10];
                struct tm dueDate;
                printf("Enter description: ");
                scanf(" %[^\n]", description);
                printf("Enter due date (YYYY-MM-DD): ");
                scanf("%d-%d-%d", &dueDate.tm_year, &dueDate.tm_mon, &dueDate.tm_mday);
                dueDate.tm_year -= 1900; // Adjust year for tm struct
                dueDate.tm_mon -= 1;     // Adjust month for tm struct
                printf("Enter priority (High, Medium, Low): ");
                scanf("%s", priority);
                addTask(&manager, description, dueDate, priority);
                break;
            }
            case 2: 
                listTasks(&manager);
                break;
            case 3: 
            {
                int id;
                printf("Enter task ID to complete: ");
                scanf("%d", &id);
                completeTask(&manager, id);
                break;
            }
            case 4: 
            {
                int id;
                printf("Enter task ID to delete: ");
                scanf("%d", &id);
                deleteTask(&manager, id);
                break;
            }
            case 5: 
            {
                char keyword[256];
                printf("Enter keyword to search: ");
                scanf(" %[^\n]", keyword);
                searchTasks(&manager, keyword);
                break;
            }
            case 6: 
            {
                char criteria[10], value[256];
                printf("Enter filter criteria (priority, duedate, status): ");
                scanf("%s", criteria);
                printf("Enter value for filter: ");
                scanf(" %[^\n]", value);
                filterTasks(&manager, criteria, value);
                break;
            }
            case 7: 
            {
                char filename[256];
                printf("Enter filename to save tasks: ");
                scanf("%s", filename);
                saveTasks(&manager, filename);
                break;
            }
            case 8: 
            {
                char filename[256];
                printf("Enter filename to load tasks: ");
                scanf("%s", filename);
                loadTasks(&manager, filename);
                break;
            }
            default:
                printf("Invalid option!\n");
                break;
        }
    }
    
    return 0;
}
