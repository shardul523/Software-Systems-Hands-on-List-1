/*
============================================================================
Name : 4.c

Author : Shardul Sisodiya

Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.

Date: 10th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("Please provide the name of the file to be opened\n");
        return 1;
    }

    const char* filePath = argv[1];

    int fdv = open(filePath, O_RDWR);

    if (fdv == -1) {
        printf("File could not be opened successfully.\n");
        return 1;
    }

    printf("File opened successfully in read-write mode.\n");

    return 0;
}


/*
============================================================================
OUTPUT:
File opened successfully in read-write mode.
============================================================================
*/
