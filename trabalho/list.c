/**
 * Various list operations
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"


// add a new task to the list of tasks
void insert(struct node **head, Task *newTask) {
    // create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->task = newTask;
    newNode->next = NULL;

    // if list is empty, set head to the new node
    if (*head == NULL) {
        *head = newNode;
    } else {
        // find the last node in the list
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }

        // add the new node to the end of the list
        current->next = newNode;
    }
}


// delete the selected task from the list
void delete(struct node **head, Task *task) {
    struct node *temp;
    struct node *prev;

    temp = *head;
    // special case - beginning of list
    if (strcmp(task->name,temp->task->name) == 0) {
        *head = (*head)->next;
    }
    else {
        // interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

// traverse the list
void traverse(struct node *head) {
     printf("Task List:\n");
    struct node *current = head;
    while (current != NULL) {
        printf("Task: %s, Priority: %d, Burst: %d\n", current->task->name, current->task->priority, current->task->burst);
        current = current->next;
    }
    printf("\n");
}


Task* pickNext(struct node **head) {
    if (*head == NULL) {
        return NULL;
    }
    return (*head)->task;
}
void sortListByPriority(struct node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        // Lista vazia ou com apenas um elemento, não é necessário ordenar
        return;
    }

    struct node *sorted = NULL;
    struct node *current = *head;

    while (current != NULL) {
        struct node *next = current->next;

        if (sorted == NULL || current->task->priority < sorted->task->priority) {
            // Inserir no início da lista ordenada
            current->next = sorted;
            sorted = current;
        } else {
            // Procurar a posição correta na lista ordenada
            struct node *temp = sorted;
            while (temp->next != NULL && current->task->priority >= temp->next->task->priority) {
                temp = temp->next;
            }
            // Inserir após temp
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sorted;
}

