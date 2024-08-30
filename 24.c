/*
============================================================================
Name : 24.c

Author : Shardul Sisodiya

Description : Write a program to create an orphan process.

Date: 30th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t child_pid = fork();

    switch(child_pid) {
        case -1:
            perror("Child process could not be created");
            return 1;
        case 0:
            printf("Child process going to sleep for 10s\n");
            sleep(10);
            printf("Child Process - Process ID: %d, Parent Process ID: %d\n", getpid(), getppid());
            break;
        default:
            printf("Parent process ID before exiting: %d\n", getpid());
    }

    return 0;
}

/*
============================================================================
OUTPUT:
Parent process ID before exiting: 31729
Child process going to sleep for 10s
Child Process - Process ID: 31730, Parent Process ID: 1541
============================================================================
*/
