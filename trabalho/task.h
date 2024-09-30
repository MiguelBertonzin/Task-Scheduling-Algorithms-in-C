/**
 * Representation of a task in the system.
 */

#ifndef TASK_H
#define TASK_H

typedef struct task {
    char *name;
    int tid;
    int priority;
    int burst;
    int isReady;        //esta pronto ou nao
    int burstRemaining; // novo campo para rastrear o tempo de burst restante
} Task;


#endif
