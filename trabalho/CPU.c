/**
 * "Virtual" CPU that also maintains track of system time.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUANTUM 25
#include "task.h"

// run this task for the specified time slice
void run_fcfs(Task *task, int slice) {
    printf("\nExecuting Task:\n");
    printf("-------------------------\n");
    printf("Task:       %s\n", task->name);
    printf("Priority:   %d\n", task->priority);
    printf("Burst:      %d\n", task->burst);
    printf("Remaining:  %d\n", slice);
    printf("-------------------------\n");
    printf("Task [%s] completed.\n", task->name);
}
void run(Task *task, int slice) {
    printf("Executing task: %s\n", task->name);
    int quantum = QUANTUM;

    if (task->burstRemaining <= quantum) {
        printf("Running task: %s, Remaining burst: %d\n", task->name, task->burstRemaining);
        task->burstRemaining = 0;
    } else {
        printf("Running task: %s, Remaining burst: %d\n", task->name, task->burstRemaining);
        task->burstRemaining -= quantum;
    }

    if (task->burstRemaining == 0) {
        printf("Task completed: %s\n\n", task->name);
        task->isReady = 0;  // marcar a tarefa como concluída
    } else {
        printf("Task not completed: %s\n\n", task->name);
        task->isReady = 1;  // marcar a tarefa como pronta para execução novamente
    }
}








