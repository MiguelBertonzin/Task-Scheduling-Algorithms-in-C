#include "stdlib.h"
#include "stddef.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "schedule_rr_p.h"
#include "list.h"
#include "task.h"
#include "CPU.h"



// list of tasks
//struct node *head = NULL;
Task *currentTask;

int getNextTaskId() {
    srand(time(NULL)); // inicializa a semente de geração de números aleatórios
    return rand() % 11;  // gera um número aleatório no intervalo de 0 a 10
}

void add3(struct node **head, char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = name;
    new_task->priority = priority;
    new_task->burst = burst;
    new_task->burstRemaining = burst;
    new_task->isReady = 1; // definir como pronta
    insert(head, new_task);
}

// invoke the scheduler
void schedule_rr_p(struct node **head) {
    sortListByPriority(head);
    traverse(*head);

    int currentPriority = 1; // Prioridade inicial
    while (*head != NULL) {
        struct node *temp = *head;
        int allTasksNotReady = 1; // Variável para verificar se todas as tarefas não estão prontas

        while (temp != NULL) {
            if (temp->task->isReady == 1 && temp->task->priority == currentPriority) {
                allTasksNotReady = 0; // Pelo menos uma tarefa com a prioridade atual está pronta
                currentTask = temp->task;
                break;
            }
            temp = temp->next;
        }

        // Se nenhuma tarefa com a prioridade atual estiver pronta, passa para a próxima prioridade
        if (allTasksNotReady) {
            currentPriority++;
            continue;
        }

        printf("Current head: %s\n", currentTask->name);
        run(currentTask, currentTask->burstRemaining); // Executa a tarefa atual

        if (currentTask->burstRemaining > 0) {
            // Atualizar o estado da tarefa e colocá-la de volta na fila
            currentTask->isReady = 1;
            delete(head, currentTask);
            insert(head, currentTask);
        } else {
            // Tarefa concluída, liberar memória
            free(currentTask->name);
            free(currentTask);
            currentTask = NULL;
        }
    }
}






void printTaskList(struct node *head) {
    printf("Task List:\n");
    struct node *current = head;
    while (current != NULL) {
        printf("Task: %s, Priority: %d\n", current->task->name, current->task->priority);
        current = current->next;
    }
    printf("\n");
}

