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
#include <stdlib.h>

/* 
const int MAX_STRING_LENGTH = 500;
const int MAX_TASKS = 30;
another way to do it:
*/
#define MAX_STRING_LENGTH 500
#define MAX_TASKS 30

char** load_tasks(char **tasks, int* size, int* max_str_len);

void save_tasks(char **tasks, int* size);
void print_tasks(char **tasks, int* size);
void remove_task(char **tasks, int* size, int index_to_remove);
char ** add_task(char **tasks, int* size, char task[], int* max_str_len);
void main_menu(char **tasks, int* size);

int main(int argc, char* argv[]) {
    char **tasks;
    int size, max_str_len=0;

    // load tasks (later from file)
    tasks = load_tasks(tasks, &size, &max_str_len);
    print_tasks(tasks, &size);
    
    // check if argument added
    // if yes: add string to tasks
    if (argc == 2) {
        if(sizeof(argv[1]) > max_str_len)
            max_str_len = sizeof(argv[1]);
        tasks = add_task(tasks, &size, argv[1], &max_str_len);
        save_tasks(tasks, &size);
    }
    
    main_menu(tasks, &size);
}

void main_menu(char **tasks, int* size) {
    print_tasks(tasks, size);
    printf("Write \"<index>\" to remove a task. Or \"-1\" to exit.\n");
    
    int selected_index = -1;
    scanf("%i", &selected_index);
    if (selected_index != -1) {
        remove_task(tasks, size, selected_index);
        print_tasks(tasks, size);
        save_tasks(tasks, size);
        main_menu(tasks, size);
    }
}

char ** add_task(char **tasks, int* size, char task[], int* max_str_len) {  
    // free tasks memory
    for (int i=0; i<*size; i++)
    {
        free(tasks[i]);
    }
    free(tasks);
   
    //load tasks 
    tasks = load_tasks(tasks, size, max_str_len);
    strcat(task, "\n");
    strcpy(tasks[*size-1], task);

    return tasks;
}

void print_tasks(char **tasks, int* size) {
    printf("\nTo-Do List:\n");
    for (int i = 0; i < *size; i++) {
        printf("%i: %s", i, tasks[i]);
    }
    printf("\n");
}

void save_tasks(char **tasks, int* size) {
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

char ** load_tasks(char **tasks, int* size, int* max_str_len) {
    FILE* file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading!\n");
        return NULL;
    }

    *size = 0;
    char c;

    //get max number of characters in line and number of lines
    int max=0; 
    int i=0;
    do 
        if ((c=fgetc(file))!= EOF && c!='\n') i++; 
        else { 
            *size += 1;
            if (i>max) max=i;
            i=0;
        }
    while (c!=EOF);
    
    //override the max_str_len
    if(max > *max_str_len)
        *max_str_len = max+2;
    
    printf("rows: %i cols: %i\n", *size, *max_str_len);
    /* allocate the array and strcpy*/
    tasks = malloc(*size * sizeof *tasks);
    for (i=0; i<*size; i++){
        tasks[i] = malloc(*max_str_len * sizeof *tasks[i]);
    }

    // start reading file again
    rewind(file);    
    i = 0; 
    char line[*max_str_len];       
    while(fgets(line, sizeof(line), file) != NULL) {
        strcpy(tasks[i], line);
        i++;
    }

    fclose(file);

    return tasks;
}

void remove_task(char **tasks, int* size, int index_to_remove) {
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