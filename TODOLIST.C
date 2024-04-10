#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 50

struct Task {
    char description[MAX_LENGTH];
    int done;
};

struct Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(const char *description) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Too many tasks\n");
        return;
    }
    strncpy(tasks[num_tasks].description, description, MAX_LENGTH - 1);
    tasks[num_tasks].description[MAX_LENGTH - 1] = '\0';
    tasks[num_tasks].done = 0;
    num_tasks++;
    printf("Task added successfully\n");
}

void mark_done(int index) {
    if (index < 0 || index >= num_tasks) {
        printf("Error: Invalid task index\n");
        return;
    }
    tasks[index].done = 1;
    printf("Task marked as done\n");
}

void remove_task(int index) {
       int i ;
    if (index < 0 || index >= num_tasks) {
	printf("Error: Invalid task index\n");
	return;
    }
    for(i = index; i < num_tasks - 1; i++) {
	strcpy(tasks[i].description, tasks[i + 1].description);
	tasks[i].done = tasks[i + 1].done;
    }
    num_tasks--;
    printf("Task removed successfully\n");
}

void print_tasks() {
     int i;
    printf("To-Do List:\n");
    for (i = 0; i < num_tasks; i++) {
	printf("%d. %s %s\n", i + 1, tasks[i].done ? "X" : " ", tasks[i].description);
    }
}
void  main() {
    int choice, index;
    char description[MAX_LENGTH];

    while (1) {
	printf("\n1. Add Task\n2. Mark Task as Done\n3. Remove Task\n4. Print Tasks\n5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter task description: ");
		scanf(" %s", description);
		add_task(description);
		break;
	    case 2:
		printf("Enter task index to mark as done: ");
		scanf("%d", &index);
		mark_done(index - 1);
		break;

	    case 3:
		printf("Enter task index to remove: ");
		scanf("%d", &index);
		remove_task(index - 1);
		break;
	    case 4:
		print_tasks();
		break;
	    case 5:
		printf("Exiting program...\n");
		exit(0);
	    default:
		printf("Invalid choice\n");
	}
    }

}