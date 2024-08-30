/*
============================================================================
Name : 12.c

Author : Shardul Sisodiya

Description : Write a program to find out the opening mode of a file. Use fcntl.

Date: 28th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int printOpeningMode(int fd) {
    int flags = fcntl(fd, F_GETFL);

    if (flags == -1) return -1;

    int acc_mode = flags & O_ACCMODE;

    printf("File with file descriptor %d, is open in ", fd);

    if (acc_mode == O_RDONLY)
        printf("READ-ONLY MODE\n");
    else if (acc_mode == O_WRONLY)
        printf("WRITE-ONLY MODE\n");
    else
        printf("READ-WRITE MODE\n");

    return 0;
}

int main(void) {
    int rd_fd = open("sample.txt", O_RDONLY);
    int wr_fd = open("sample.txt", O_WRONLY);
    int rdwr_fd = open("sample.txt", O_RDWR);

    if (rd_fd < 0 || wr_fd < 0 || rdwr_fd < 0) {
        perror("Could not open the file successfully");
        exit(EXIT_FAILURE);
    }

    if (printOpeningMode(rd_fd) < 0 || printOpeningMode(wr_fd) < 0 || printOpeningMode(rdwr_fd) < 0) {
        perror("File opening mode could not be accessed");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}


/*
============================================================================
OUTPUT:
File with file descriptor 3, is open in READ-ONLY MODE
File with file descriptor 4, is open in WRITE-ONLY MODE
File with file descriptor 5, is open in READ-WRITE MODE
============================================================================
*/
