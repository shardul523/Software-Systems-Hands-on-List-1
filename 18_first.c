/*
============================================================================
Name : 18_first.c

Author : Shardul Sisodiya

Description :
Write a program to perform Record locking.
    a. Implement write lock
    b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.

Date: 28th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_NAME "records"

struct Record {
    int key;
    int val;
};

int main(void) {
    struct Record r[3];

    for (int i = 0; i < 3; i++) {
        r[i].key = i + 1;
        r[i].val = 0;
    }

    int fd = open(FILE_NAME, O_CREAT | O_WRONLY, 0644);

    if (fd == -1) {
        perror("Could not open the records file");
        exit(EXIT_FAILURE);
    }

    if (write(fd, r, sizeof(struct Record) * 3) < 0) {
        perror("Could not write the records to file");
        exit(EXIT_FAILURE);
    }

    printf("Records successfully created\n");

    close(fd);

    return 0;
}

/*
============================================================================
OUTPUT:
Records successfully created
============================================================================
*/
