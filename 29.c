/*
============================================================================
Name : 29.c

Author : Shardul Sisodiya

Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

void print_scheduler(pid_t pid) {
    int scheduler = sched_getscheduler(pid);
    switch (scheduler) {
        case SCHED_OTHER:
            printf("Current scheduler is SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Current scheduler is SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduler is SCHED_RR\n");
            break;
        default:
            printf("Unknown scheduler!\n");
    }
}

int main() {
    pid_t pid = 0;

    print_scheduler(pid);

    struct sched_param param;
    param.sched_priority = sched_get_priority_max(SCHED_RR);

    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("Could not set the scheduler to SCHED_FIFO");
        exit(EXIT_FAILURE);
    } else {
        printf("Successfully set scheduler to SCHED_FIFO\n");
        print_scheduler(pid);
    }

    param.sched_priority = sched_get_priority_max(SCHED_RR);

    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("Could not set the scheduler to SCHED_RR");
        exit(EXIT_FAILURE);
    } else {
        printf("Successfully set scheduler to SCHED_RR\n");
        print_scheduler(pid);
    }

    return 0;
}


/*
============================================================================
OUTPUT:
Current scheduler is SCHED_OTHER
Successfully set scheduler to SCHED_FIFO
Current scheduler is SCHED_FIFO
Successfully set scheduler to SCHED_RR
Current scheduler is SCHED_RR
============================================================================
*/
