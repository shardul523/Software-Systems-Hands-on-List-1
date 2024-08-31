/*
============================================================================
Name : 1c.c

Author : Shardul Sisodiya

Description :
Create the following types of a files using (i) shell command (ii) system call
    c. FIFO (mkfifo Library Function or mknod system call)

Date: 8th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <fifo_name>\n", argv[0]);
        return 1;
    }

    if(mkfifo(argv[1], 0666) == 0) {
        printf("FIFO created successfully\n");
        return 0;
    }

    perror("FIFO could not be created");
    return 1;
}

/*
============================================================================
OUTPUT:
FIFO created successfully
============================================================================
*/
