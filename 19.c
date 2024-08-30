/*
============================================================================
Name : 19.c

Author : Shardul Sisodiya

Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Date: 29th Aug, 2024.
============================================================================
*/

#include <bits/time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void) {
    struct timespec start_time, end_time;
    pid_t pid;
    double time_taken = 0;

    if (clock_gettime(CLOCK_MONOTONIC, &start_time) == -1) {
        perror("Timer could not be started");
        return 1;
    }

    pid = getpid();

    if (clock_gettime(CLOCK_MONOTONIC, &end_time) == -1) {
        perror("Timer could not be stopped");
        return 1;
    }

    time_taken = end_time.tv_sec - start_time.tv_sec + (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;

    printf("Process ID of the current process: %d\n", pid);
    printf("Time taken for getpid system call: %.8lf sec\n", time_taken);

    return 0;
}


/*
============================================================================
OUTPUT:
Process ID of the current process: 36843
Time taken for getpid system call: 0.00000641 sec
============================================================================
*/
