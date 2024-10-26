# Task Manager

A simple console-based task management application that allows users to add, list, complete, delete, search, and filter tasks. The tasks can be saved to and loaded from a file.

## Features

- **Add Task:** Create a new task with a description, due date, and priority.
- **List Tasks:** View all tasks in the manager.
- **Complete Task:** Mark a task as completed.
- **Delete Task:** Remove a task from the list.
- **Search Tasks:** Find tasks by keyword in their descriptions.
- **Filter Tasks:** Filter tasks by priority, due date, or completion status.
- **Save Tasks:** Save the current list of tasks to a file.
- **Load Tasks:** Load tasks from a specified file.

## Requirements

- C compiler (e.g., GCC)
- Standard C library

## File Structure

```
/TaskManager
├── main.c           # Main application file
├── Task.h           # Task data structure and function declarations
├── Task.c           # Task functions implementation
├── TaskManager.h    # TaskManager data structure and function declarations
└── TaskManager.c    # TaskManager functions implementation
```

## Compilation

To compile the application, run the following command in your terminal:

```bash
gcc main.c Task.c TaskManager.c -o task_manager
```

## Usage

1. Run the compiled application:

   ```bash
   ./task_manager
   ```

2. Follow the on-screen menu to manage your tasks.

## Example

```
Task Manager
1. Add Task
2. List Tasks
3. Complete Task
4. Delete Task
5. Search Tasks
6. Filter Tasks
7. Save Tasks
8. Load Tasks
9. Exit
Select an option:
```

## Contributing

If you'd like to contribute to this project, feel free to fork the repository and submit a pull request. 

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
