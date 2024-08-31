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

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t child1, child2;

    child1 = fork();

    if (child1 == -1) {
        perror("There was an error in creating child process to run the executable");
        exit(EXIT_FAILURE);
    }

    if (child1 == 0) {
        char* args[] = {"date", NULL};
        execvp(args[0], args);
        perror("There was an error in executing the executable");
        exit(EXIT_FAILURE);
    }

    child2 = fork();

    if (child2 == -1) {
        perror("There was an error in creating the second child process");
        exit(EXIT_FAILURE);
    }

    if (child2 == 0) {
    	char *args[]={"echo", "Hello World", NULL};
    	execvp(args[0],args);
        perror("There was an error in executing the executable");
        exit(EXIT_FAILURE);
    }

    wait(NULL);
    wait(NULL);

	printf("Main Process Exiting\n");
	return 0;
}

/*
============================================================================
OUTPUT:
Hello World
Sat Aug 31 05:22:36 PM IST 2024
Main Process Exiting
============================================================================
*/
