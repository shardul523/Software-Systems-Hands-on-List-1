/*
============================================================================
Name : 3.c

Author : Shardul Sisodiya

Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call

Date: 9th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please enter the filename to be created\n");
    }

    const char* filename = argv[1];

    int file = creat(filename, 0644);

    printf("File created\n");
    printf("File Descriptor Value: %d\n", file);

    return 0;
}


/*
============================================================================
OUTPUT:
File created
File Descriptor Value: 3
============================================================================
*/
