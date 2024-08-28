/**
    NAL: Napiši program "To-Do List", ki go omogočal shranjevanje nalog, ki jih 
    morate opraviti. Program mora omogočati:
    => nalaganje nalog iz datoteke "load_tasks"
    => shranjevanje nalog "save_task"
    => pintanje nalog "print_task"
    => odstranjevanje naloge "remove_task"
    => dodajanje nalog implementiraj preko argumentov v ukazni vrstici "add_task"
    => ispis menija "main_menu"

    IZPIS: $  ./todo.out
    To-Do List:
    0: Learn Git
    1: Learn C
    2: Make HW

    Write "<index>" to remove a task. Or "-1" to exit.
    0

    To-Do List:
    0: Learn C
    1: Make HW

    IZPIS: ./todo.out "Learn pointers"
    To-Do List:
    0: Learn C
    1: Make HW
    2: Learn pointers

    Write "<index>" to remove a task. Or "-1" to exit.

    Za boljše razumevanje naloge lahko sam preizkusiš delovanje programa.

*/

#include <stdio.h>
#include <string.h>

/* 
const int MAX_STRING_LENGTH = 500;
const int MAX_TASKS = 30;
another way to do it:
*/
#define MAX_STRING_LENGTH 500
#define MAX_TASKS 30

void load_tasks(char tasks[][MAX_STRING_LENGTH], int* size);
void save_tasks(char tasks[][MAX_STRING_LENGTH], int* size);
void print_tasks(char tasks[][MAX_STRING_LENGTH], int* size);
void remove_task(char tasks[][MAX_STRING_LENGTH], int* size, int index_to_remove);
void add_task(char tasks[][MAX_STRING_LENGTH], int* size, char task[]);
void main_menu(char tasks[][MAX_STRING_LENGTH], int* size);

int main(int argc, char* argv[]) {
    // init varables
    char tasks[MAX_TASKS][MAX_STRING_LENGTH];
    int size;

    // load tasks (later from file)
    load_tasks(tasks, &size);

    // check if argument added
    // if yes: add string to tasks
    if (argc == 2) {
        add_task(tasks, &size, argv[1]);
        save_tasks(tasks, &size);
    }
    
    main_menu(tasks, &size);
}

void main_menu(char tasks[][MAX_STRING_LENGTH], int* size) {
    print_tasks(tasks, size);
    printf("Write \"<index>\" to remove a task. Or \"-1\" to exit.\n");
    
    //char line[50];
    //fgets(line, sizeof(line), stdin);
    int selected_index = -1;
    scanf("%i", &selected_index);
    if (selected_index != -1) {
        remove_task(tasks, size, selected_index);
        print_tasks(tasks, size);
        save_tasks(tasks, size);
        main_menu(tasks, size);
    }
}

void add_task(char tasks[][MAX_STRING_LENGTH], int* size, char task[]) {
    // check if we can add to the list
    if(*size >= MAX_TASKS) {
        printf("Sorry, task list is full! Can not add a new item!\n");
        return;
    }
    strcat(task, "\n");
    strcpy(tasks[*size], task);
    *size += 1;
}

void print_tasks(char tasks[][MAX_STRING_LENGTH], int* size) {
    printf("\nTo-Do List:\n");
    for (int i = 0; i < *size; i++) {
        printf("%i: %s", i, tasks[i]);
    }
    printf("\n");
}

void save_tasks(char tasks[][MAX_STRING_LENGTH], int* size) {
    // open file
    FILE* file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing!\n");
        return;
    }

    // write each line in file
    for(int i = 0 ; i < *size ; i++) {
        fprintf(file, "%s", tasks[i]);
    }

    // close the file
    fclose(file);
}

void load_tasks(char tasks[][MAX_STRING_LENGTH], int* size) {
    FILE* file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading!\n");
        return;
    }

    *size = 0;
    char line[MAX_STRING_LENGTH];
    
    while(fgets(line, sizeof(line), file) != NULL) {
        strcpy(tasks[*size], line);
        *size += 1;
    }

    fclose(file);
}

void remove_task(char tasks[][MAX_STRING_LENGTH], int* size, int index_to_remove) {
    if (index_to_remove >= *size) {
        return;
    }

    // Shift the elements after the element to be removed one position to the left
    for (int i = index_to_remove; i < (*size - 1); i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }

    // Decrement the size of the array
    *size -= 1;
}