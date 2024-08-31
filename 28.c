/*
============================================================================
Name : 28.c

Author : Shardul Sisodiya

Description : Write a program to get maximum and minimum real time priority.

Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sched.h>

void print_priority_range(int policy) {
    int max_prio = sched_get_priority_max(policy);
    int min_prio = sched_get_priority_min(policy);

    if (max_prio == -1 || min_prio == -1) {
        perror("Error getting priority range");
        return;
    }

    char* policy_name;

    switch(policy) {
        case SCHED_FIFO:
            policy_name = "SCHED_FIFO";
            break;
        case SCHED_RR:
            policy_name = "SCHED_RR";
            break;
        case SCHED_OTHER:
            policy_name = "SCHED_OTHER";
            break;
        default:
            policy_name = "Unknown";
    }

    printf("%s priority range: %d (min) to %d (max)\n", policy_name, min_prio, max_prio);
}

int main() {
    printf("Real-time Priority Ranges:\n");
    print_priority_range(SCHED_FIFO);
    print_priority_range(SCHED_RR);

    return 0;
}

/*
============================================================================
OUTPUT:
Real-time Priority Ranges:
SCHED_FIFO priority range: 1 (min) to 99 (max)
SCHED_RR priority range: 1 (min) to 99 (max)
============================================================================
*/
