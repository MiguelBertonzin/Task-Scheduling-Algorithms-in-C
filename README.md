The main focus of this work was Scheduling in Operating Systems. The project, developed in C language, aimed to implement three task scheduling algorithms: Round-Robin (RR), Round-Robin with Priority (RRp), and First Come, First Served (FCFS).

The system was designed to read a set of tasks from a file and organize them into a queue (ready queue). Then, the tasks were scheduled according to the selected algorithm.

The main files developed were:

driver.c: Responsible for the main() function, which reads the tasks, inserts them into the ready queue, and calls the scheduler.
CPU.c/.h: Monitors and displays which task is being executed.
list.c/.h: Implements the linked list structure to insert, delete, and traverse tasks.
task.h: Defines the structure of a task.
scheduler.h: Implements the scheduling functions, with the RR, RRp, and FCFS algorithms.

During the development, I extensively used data structures such as queue, stack, and linked list.
