/*
============================================================================
Name : 22.c

Author : Shardul Sisodiya

Description :
Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.

Date: 30th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        perror("Please specify the file to be writtent to");
        return 1;
    }

    int fd = open(argv[1], O_WRONLY);
    char child_buff[] = "Written by child process\n";
    char parent_buff[] = "Written by parent process\n";
    pid_t child_pid = fork();

    switch (child_pid) {
        case -1:
            perror("There was an error in creating the child process");
            exit(EXIT_FAILURE);
        case 0:
            if (write(fd, child_buff, sizeof(child_buff) - 1) < 0) {
                perror("There was an error writing using the child process");
                exit(EXIT_FAILURE);
            }
            printf("File written to successfully using the child process\n");
            break;
        default:
            if (write(fd, parent_buff, sizeof(parent_buff) - 1) < 0) {
                perror("There was an error writing using the parent process");
                exit(EXIT_FAILURE);
            }
            printf("File written to successfully using the parent process\n");
    }

    exit(EXIT_SUCCESS);
}


/*
============================================================================
OUTPUT:
File written to successfully using the parent process
File written to successfully using the child process
============================================================================
*/
