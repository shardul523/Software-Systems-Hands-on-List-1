/*
============================================================================
Name : 26.c

Author : Shardul Sisodiya

Description :
Write a program to execute an executable program.
    a. use some executable program
    b. pass some input to an executable program.

Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    pid_t child_id = fork();
    char* exec_name;
    char** argv;
    int argc;

    if (child_id == -1) {
        perror("Process could not be forked");
        return 1;
    }

    if (child_id != 0) {
        printf("Enter the name of the executable to be executed: ");
        scanf("%s", exec_name);

        printf("Enter the number of input arguements to be passed: ");
        scanf("%d", &argc);

        argv = calloc(argc + 1, sizeof(char*));
        argv[0] = exec_name;

        printf("Enter the list of arguements: ");

        for (int i = 1; i <= argc; i++)
            scanf("%s", argv[i]);
    } else {
        execvp(exec_name, argv);
        printf("Could not execute the process properly\n");
        return 1;
    }

    printf("Waiting for executable to finish executing\n");
    wait(NULL);
    printf("Execution completed\n");

    return 0;
}
