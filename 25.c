/*
============================================================================
Name : 25.c

Author : Shardul Sisodiya

Description : Write a program to create three child processes. The parent should wait for a particular child

Date: 30th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        perror("Please specify which child process to wait for (1 / 2 / 3)");
        return 1;
    }

    int index = argv[1][0] - '0' - 1;
    pid_t child_pids[3];
    int status;

    if (index < 0 || index > 2) index = 0;

    for (int i = 0; i < 3; i++) {
        child_pids[i] = fork();
        if (child_pids[i] == 0) {
            printf("Child Process %d: Executing for %ds\n", i + 1, (i + 1) * 5);
            sleep((i + 1) * 5);
            printf("Child Process %d: Completed\n", i + 1);
            return 0;
        }
    }

    printf("Main Process: Waiting for child process %d to complete\n", index + 1);

    waitpid(child_pids[index], &status, 0);

    wait(NULL);
    wait(NULL);

    printf("Main Process exiting\n");

    return 0;
}

/*
============================================================================
OUTPUT:
Child Process 1: Executing for 5s
Main Process: Waiting for child process 3 to complete
Child Process 2: Executing for 10s
Child Process 3: Executing for 15s
Child Process 1: Completed
Child Process 2: Completed
Child Process 3: Completed
Main Process exiting
============================================================================
*/
