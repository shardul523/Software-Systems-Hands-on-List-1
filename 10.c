/*
============================================================================
Name : 10.c

Author : Shardul Sisodiya

Description :
Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
    a. check the return value of lseek
    b. open the file with od and check the empty spaces in between the data.

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        perror("Please specify the name of the file to be written to");
        return 1;
    }

    char first[10] = "HelloWorld";
    char last[10] = "byebyebye!";
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);

    if (fd < 0) {
        perror("There was some error. Please try again!\n");
        exit(EXIT_FAILURE);
    }

    if (write(fd, first, 10) < 0) {
        perror("Could not write to the file\n");
        exit(EXIT_FAILURE);
    }

    if (lseek(fd, 10, SEEK_CUR) < 0) {
        perror("Could not move the file pointer 10 spaces ahead\n");
        exit(EXIT_FAILURE);
    }

    if (write(fd, last, 10) < 0) {
        perror("Could not write to the file\n");
        exit(EXIT_FAILURE);
    }

    printf("File written to successfully\n");

    close(fd);

    return 0;
}


/*
============================================================================
OUTPUT:
File written to successfully
============================================================================
*/
