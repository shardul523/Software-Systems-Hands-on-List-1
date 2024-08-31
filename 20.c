/*
============================================================================
Name : 20.c

Author : Shardul Sisodiya

Description : Find out the priority of your running program. Modify the priority with nice command.

Date: 31st Aug, 2024.
============================================================================
*/

#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    int curr_priority = getpriority(PRIO_PROCESS, 0);

    printf("Current Priority of the running program: %d\n", curr_priority);

    int new_priority = nice(5);

    printf("New Priority of the running program: %d\n", new_priority);

    return 0;
}

/*
============================================================================
OUTPUT:
Current Priority of the running program: 0
New Priority of the running program: 5
============================================================================
*/
