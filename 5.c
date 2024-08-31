/*
============================================================================
Name : 5.c

Author : Shardul Sisodiya

Description :
Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.

Date: 10th Aug, 2024.
============================================================================
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void) {
    int num_files = 5;
    for (int i = 1; i <= num_files; i++) {
        char* index = (char*)calloc(2, sizeof(char));
        index[0] = '0' + i;
        index[1] = 0;
        char filename[10] = "file";
        strcat(filename, index);
        int fd = creat(filename, 0644);
        if (fd == -1) {
            printf("%s could not be created", filename);
            return 1;
        }
    }

    printf("5 new files created\n");

    for(;;);

    return 0;
}

/*
============================================================================
OUTPUT:
5 new files created
============================================================================
*/
