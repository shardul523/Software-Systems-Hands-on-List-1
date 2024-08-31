/*
============================================================================
Name : 27b.c

Author : Shardul Sisodiya

Description :
Write a program to execute ls -Rl by the following system calls
    b. execlp

Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_id = fork();

    if (child_id == -1) {
        perror("There was an error in forking the process\n");
        return 1;
    }

    if (child_id == 0) {
        execlp("ls", "ls", "-Rl", NULL);
        perror("Could not execute the command");
        return 1;
    } else {
        printf("Executing ls -Rl as child process using exclp\n");
        wait(NULL);
    }

    return 0;
}

/*
============================================================================
OUTPUT:
Executing ls -Rl as child process usign execlp
.:
total 120
-rw-rw-r-- 1 shardul shardul  1621 Aug 28 22:26 10.c
-rw-rw-r-- 1 shardul shardul  2049 Aug 28 22:23 11.c
-rw-rw-r-- 1 shardul shardul  1624 Aug 28 22:51 12.c
-rw-rw-r-- 1 shardul shardul  1361 Aug 28 23:05 13.c
-rw-rw-r-- 1 shardul shardul  1927 Aug 29 11:31 14.c
-rw-rw-r-- 1 shardul shardul   731 Aug 29 11:32 15.c
-rw-rw-r-- 1 shardul shardul  2278 Aug 30 02:26 16.c
-rw-rw-r-- 1 shardul shardul  1322 Aug 30 02:42 19.c
-rw-rw-r-- 1 shardul shardul  1009 Aug 30 18:44 21.c
-rw-rw-r-- 1 shardul shardul  1843 Aug 30 19:15 22.c
-rw-rw-r-- 1 shardul shardul  1274 Aug 30 19:16 23.c
-rw-rw-r-- 1 shardul shardul  1125 Aug 30 19:24 24.c
-rw-rw-r-- 1 shardul shardul  1634 Aug 30 23:08 25.c
-rw-rw-r-- 1 shardul shardul  1342 Aug 30 23:36 26.c
-rw-rw-r-- 1 shardul shardul   841 Aug 31 10:45 27a.c
-rw-rw-r-- 1 shardul shardul   792 Aug 31 10:50 27b.c
-rw-rw-r-- 1 shardul shardul   838 Aug 31 10:50 27c.c
-rw-rw-r-- 1 shardul shardul   833 Aug 31 10:54 27d.c
-rw-rw-r-- 1 shardul shardul   827 Aug 31 10:55 27e.c
-rw-rw-r-- 1 shardul shardul   303 Aug  9 16:11 3.c
-rw-rw-r-- 1 shardul shardul   479 Aug 10 01:14 4.c
-rw-rw-r-- 1 shardul shardul   576 Aug 27 22:40 5.c
-rw-rw-r-- 1 shardul shardul   422 Aug 27 22:40 6.c
-rw-rw-r-- 1 shardul shardul  1069 Aug 27 22:43 7.c
-rw-rw-r-- 1 shardul shardul  1258 Aug 27 22:43 8.c
-rw-rw-r-- 1 shardul shardul  1104 Aug 28 18:13 9.c
-rwxrwxr-x 1 shardul shardul 16168 Aug 31 10:55 a.out
============================================================================
*/
