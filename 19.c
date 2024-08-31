/*
============================================================================
Name : 19.c

Author : Shardul Sisodiya

Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Date: 29th Aug, 2024.
============================================================================
*/

#include <sys/time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define FREQ 1 / (4.7 * 1e9)

unsigned long long rdtsc() {
    unsigned long long dst;
    __asm__ __volatile__("rdtsc":"=A"(dst));
    return dst;
}

int main(void) {
    unsigned long long start_time, end_time;
    pid_t pid;
    long double time_taken = 0;

    start_time = rdtsc();

    pid = getpid();

    end_time = rdtsc();

    time_taken = (end_time - start_time) * FREQ;

    printf("Process ID of the current process: %d\n", pid);
    printf("Time taken for getpid system call: %.9Lf sec\n", time_taken);

    return 0;
}


/*
============================================================================
OUTPUT:
Process ID of the current process: 19905
Time taken for getpid system call: 0.000003023 sec
============================================================================
*/
