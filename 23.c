/*
============================================================================
Name : 23.c

Author : Shardul Sisodiya

Description : Write a program to create a Zombie state of the running program.

Date: 30th Aug, 2024.
============================================================================
*/


#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void) {
    pid_t child_pid = fork();

    switch(child_pid) {
        case -1:
            perror("There was an error in creating child process");
            return 1;
        case 0:
            printf("This is the child process\n");
            break;
        default:
            printf("This is the parent process\n");
            printf("Going to sleep for 10 sec during which child process is in zombie state\n");
            sleep(10);
            wait(NULL);
            printf("Reaped the child process from zombie state\n");
    }

    return 0;
}

/*
============================================================================
OUTPUT:
This is the parent process
Going to sleep for 10 sec during which child process is in zombie state
This is the child process
Released the child process from zombie state
============================================================================
*/
