/*
============================================================================
Name : 17b.c

Author : Shardul Sisodiya

Description :
Write a separate program, to open the file, implement write lock, read the ticket number,
increment the number and print the new ticket number then close the file.

Date: 28th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd = open("ticket_num", O_RDWR);
    int ticket_number;
    struct flock write_lock;

    if (fd == -1) {
        perror("Could not open the ticket number file");
        exit(EXIT_FAILURE);
    }

    write_lock.l_start = 0;
    write_lock.l_len = 0;
    write_lock.l_type = F_WRLCK;
    write_lock.l_whence = SEEK_SET;

    if (fcntl(fd, F_SETLK, &write_lock) == -1) {
        perror("Could not set write lock on the file");
        exit(EXIT_FAILURE);
    }

    printf("Write lock SET\n");

    if (read(fd, &ticket_number, sizeof(int)) < 0) {
        perror("Could not read the ticket number from the file");
        exit(EXIT_FAILURE);
    }

    ticket_number++;

    printf("New Ticket Number: %d\n", ticket_number);

    if (lseek(fd, 0, SEEK_SET) < 0) {
        perror("Could not move cursor to the beginning of the file");
        exit(EXIT_FAILURE);
    }

    if (write(fd, &ticket_number, sizeof(int)) < 0) {
        perror("Could not write the new ticket number to the file");
        exit(EXIT_FAILURE);
    }

    write_lock.l_type = F_UNLCK;

    if (fcntl(fd, F_SETLK, &write_lock) == -1) {
        perror("Could not unlock the write lock on the ticket file");
        exit(EXIT_FAILURE);
    }

    printf("Write lock REMOVED\n");

    close(fd);

    return 0;
}


/*
============================================================================
OUTPUT:
Write lock SET
New Ticket Number: 7
Write lock REMOVED
============================================================================
*/
