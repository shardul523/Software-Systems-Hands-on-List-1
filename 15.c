/*
============================================================================
Name : 15.c

Author : Shardul Sisodiya

Description : Write a program to display the environmental variable of the user (use environ).

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    extern char **environ;
    char **envp = environ;

    while (*envp != NULL) {
        printf("%s\n", *envp);
        envp++;
    }

    return 0;
}

/*
============================================================================
OUTPUT:
Prints all the environment variables
============================================================================
*/
