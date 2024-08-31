/*
============================================================================
Name : 6.c

Author : Shardul Sisodiya

Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.

Date: 19th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char* buffer = calloc(100, sizeof(char));
    ssize_t bytes_read;

    bytes_read = read(0, buffer, 99);

    if (write(1, buffer, bytes_read - 1) == -1) {
        printf("\nSomething broke!\n");
        return 1;
    }

    printf("\nRead from STDIN and prints to STDOUT\n");

    return 0;
}


/*
============================================================================
INPUT:
Hello this is Shardul

OUTPUT:
Hello this is Shardul
Read from STDIN and prints to STDOUT
============================================================================
*/
