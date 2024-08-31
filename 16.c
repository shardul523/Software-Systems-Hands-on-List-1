/*
============================================================================
Name : 16.c

Author : Shardul Sisodiya

Description :
Write a program to perform mandatory locking.
    a. Implement write lock
    b. Implement read lock

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int readlock(int fd) {
    struct flock rlock;

    memset(&rlock, 0, sizeof(rlock));

    rlock.l_type = F_RDLCK;
    rlock.l_whence = SEEK_SET;
    rlock.l_len = 0;
    rlock.l_start = 0;

    printf("Setting the read lock\n");

    if (fcntl(fd, F_SETLK, &rlock) == -1) {
        perror("File could not be locked");
        return 1;
    }

    printf("Read lock set successfully\n");

    return 0;
}

int writelock(int fd) {
    struct flock wlock;

    memset(&wlock, 0, sizeof(wlock));

    wlock.l_len = 0;
    wlock.l_start = 0;
    wlock.l_whence = SEEK_SET;
    wlock.l_type = F_WRLCK;

    printf("Setting the write lock\n");

    if (fcntl(fd, F_SETLK, &wlock) == -1) {
        perror("Could not set the write lock");
        return 1;
    }

    printf("Write lock set successfully\n");

    return 0;
}

int unlock(int fd) {
    struct flock ulock;

    memset(&ulock, 0, sizeof(ulock));

    ulock.l_len = 0;
    ulock.l_start = 0;
    ulock.l_type = F_UNLCK;
    ulock.l_whence = SEEK_SET;

    if (fcntl(fd, F_SETLK, &ulock) == -1) {
        perror("Could not remove the lock\n");
        return 1;
    }

    printf("Lock removed successfully\n");

    return 0;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s [type] <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[2], O_RDWR);

    if (fd == -1) {
        perror("Could not open the file successfully");
        exit(EXIT_FAILURE);
    }

    switch (argv[1][0]) {
        case 'r':
            if (readlock(fd) == 1) exit(EXIT_FAILURE);
            break;
        case 'w':
            if (writelock(fd) == 1) exit(EXIT_FAILURE);
            break;
        default:
            printf("Invalid lock type\n");
            exit(EXIT_FAILURE);
    }

    getchar();

    unlock(fd);

    exit(EXIT_SUCCESS);
}

/*
============================================================================
COMMAND LINE ARGUMENTS: w sample.txt

OUTPUT:
Setting the write lock
Write lock set successfully

Lock removed successfully
============================================================================
*/
