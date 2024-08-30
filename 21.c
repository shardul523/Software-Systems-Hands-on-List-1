/*
============================================================================
Name : 21.c

Author : Shardul Sisodiya

Description : Write a program, call fork and print the parent and child process id.

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t curr_pid = fork();

    switch(curr_pid) {
        case -1:
            perror("A child process could not be created\n");
            return 1;
        case 0:
            printf("The process id of the child process is: %d\n", getpid());
            break;
        default:
            printf("The process id of the parent process is: %d\n", getpid());
    }

    return 0;
}

/*
============================================================================
OUTPUT:
The process id of the parent process is: 25072
The process id of the child process is: 25073
============================================================================
*/
