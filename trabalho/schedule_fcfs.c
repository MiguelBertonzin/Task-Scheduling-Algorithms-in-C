/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "schedule_fcfs.h"
#include "list.h"
#include "task.h"
#include <time.h>

struct node *head = NULL;
Task *currentTask;
// add a task to the list
void add2(char *name, int priority, int burst) {
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->tid = getNextTaskId();
    newTask->priority = priority;
    newTask->burst = burst;
    insert(&head, newTask);
}
int getNextTaskId() {
    srand(time(NULL)); // inicializa a semente de geração de números aleatórios
    return rand() % 11;  // gera um número aleatório no intervalo de 0 a 10
}
// invoke the scheduler fcfs
void schedule_fcfs() {
    while (head != NULL) {
        currentTask = head->task; // seleciona a primeira tarefa da lista
        run_fcfs(currentTask,currentTask->burst); // executa a tarefa selecionada
        delete(&head, currentTask);
        free(currentTask);
    }
    printf("\nfinished the tasks\n");
}*/
