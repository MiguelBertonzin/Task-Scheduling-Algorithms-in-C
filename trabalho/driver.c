/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

 /*
Sistemas Operacionais
Atividade: Trabalho M2
Professor: Felipe Viel
Alunos: Diego Bourguignon Rangel e Miguel Bertonzin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "task.h"
#include "list.h"
#include "schedule_rr.h"
#include "schedule_fcfs.h"
#include "schedule_rr_p.h"
#define QUANTUM 10
#define SIZE    100

char *strsep(char **stringp, const char *delim) {//divide uma string em substrings
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp) {
            *(*stringp)++ = '\0';
        } else {
            *stringp = NULL;
        }
    }
    return rv;
}


int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;
    struct node *head = NULL;
    in = fopen("rr-schedule_pri.txt","r");

    while (fgets(task,SIZE,in) != NULL) { //pega cada linha e divide 3 sub strings
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,",")); //atoi converte as strings para inteiros usando a função
        burst = atoi(strsep(&temp,","));
        printf("Name: %s\n",name);
        printf("Priority: %d\n",priority);
        printf("Burst: %d\n",burst);

        // add the task to the scheduler's list of tasks

        add3(&head, name, priority, burst);//_rr_p e rr
        //add2(name,priority,burst);//para fsfc

        free(temp);
    }


    fclose(in);
    // invoke the scheduler
    //schedule_rr(&head);
    schedule_rr_p(&head);
    //schedule_fcfs();

    return 0;
}
