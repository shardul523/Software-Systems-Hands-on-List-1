/*
============================================================================
Name : 13.c

Author : Shardul Sisodiya

Description :
Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not

Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>


int main(void) {
    struct timeval interval;
    fd_set read_fds;
    int input;

    interval.tv_sec = 10;
    interval.tv_usec = 0;

    FD_ZERO(&read_fds);
    FD_SET(0, &read_fds);

    input = select(1, &read_fds, NULL, NULL, &interval);

    if (input == 0) {
        printf("No data was made available to read on STDIN in the last 10s\n");
    } else if (input == -1) {
        perror("There was an error during the op\n");
        exit(EXIT_FAILURE);
    } else {
        printf("There is data available to be read on STDIN\n");
    }

    return 0;
}


/*
============================================================================
INPUT:

OUTPUT:
No data was made available to read on STDIN in the last 10s

---

INPUT:
Hello world

OUTPUT:
There is data available to be read on STDIN
============================================================================
*/
