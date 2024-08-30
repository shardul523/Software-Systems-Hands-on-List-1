/*
============================================================================
Name : 11.c

Author : Shardul Sisodiya

Description :
Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
    a. use dup
    b. use dup2
    c. use fcntl

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        perror("Please specify a file as well");
        return 1;
    }

    int og_fd = open(argv[1], O_WRONLY | O_CREAT, 0777), dup_fd, dup2_fd, fcntl_fd;
    char og_str[] = "Written using OG FD\n";
    char dup_str[] = "Written using dup FD\n";
    char dup2_str[] = "Written using dup2 FD\n";
    char fcntl_str[] = "Written using fcntln FD\n";

    if (og_fd < 0) {
        perror("File does not exist or could not be opened successfully");
        return 1;
    }

    dup_fd = dup(og_fd);
    dup2_fd = dup2(og_fd, 10);
    fcntl_fd = fcntl(og_fd, F_DUPFD, og_fd);

    if (dup_fd < 0 || dup2_fd < 0 || fcntl_fd < 0) {
        perror("File descriptor could not be duplicated");
        exit(EXIT_FAILURE);
    }

    if (lseek(og_fd, 0, SEEK_END) < 0) {
        perror("File pointer could not be moved to end of the file");
        exit(EXIT_FAILURE);
    }

    if (
        write(og_fd, og_str, sizeof(og_str) - 1) < 0 ||
        write(dup_fd, dup_str, sizeof(dup_str) - 1) < 0 ||
        write(dup2_fd, dup2_str, sizeof(dup2_str) - 1) < 0 ||
        write(fcntl_fd, fcntl_str, sizeof(fcntl_str) - 1) < 0
    ) {
        perror("Error during write op");
        exit(EXIT_FAILURE);
    }

    printf("File appended successfully\n");

    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
File appended successfully
============================================================================
*/
