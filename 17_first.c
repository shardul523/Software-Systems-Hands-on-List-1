/*
============================================================================
Name : 17.c

Author : Shardul Sisodiya

Description :
Write a program to simulate online ticket reservation.
Write a program to open a file, store a ticket number and exit.

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int t_num;

    printf("Enter the ticket number to be stored: ");
    scanf("%d", &t_num);

    int fd = open("ticket_num", O_CREAT | O_RDWR, 0644);

    if (fd == -1) {
        perror("Ticket file could not be opened");
        exit(EXIT_FAILURE);
    }

    if (write(fd, &t_num, sizeof(int)) < 0) {
        perror("Could not write the ticket number to the file");
        exit(EXIT_FAILURE);
    }

    printf("Ticket number %d added to the file\n", t_num);

    exit(EXIT_SUCCESS);
}

/*
============================================================================
INPUT: 6

OUTPUT:
Enter the ticket number to be stored:
Ticket number 6 added to the file
============================================================================
*/
