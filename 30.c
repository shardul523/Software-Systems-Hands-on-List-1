/*
============================================================================
Name : 30.c

Author : Shardul Sisodiya

Description : Write a program to run a script at a specific time using a Daemon process.

Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <script_name> <hours> <minutes>\n", argv[0]);
        return 1;
    }

    int target_hour = atoi(argv[2]);
    int target_min = atoi(argv[3]);
    pid_t child_pid = fork();

    switch (child_pid) {
        case -1:
            perror("Could not create child process");
            return 1;
        case 0:
            printf("Child process with ID: %d\n", getpid());
            setsid();
    		umask(0);
    		chdir("/");
            while (1) {
                time_t now;
                struct tm *local_time;

                time(&now);
                local_time = localtime(&now);

                if (local_time->tm_hour == target_hour && local_time->tm_min == target_min) {
                    int ret = system(argv[1]);

                    if (WIFSIGNALED(ret) &&
                        (WTERMSIG(ret) == SIGINT || WTERMSIG(ret) == SIGQUIT))
                            break;
                    sleep(60);
                }
                sleep(30);
            }
            perror("Child process exited");
            break;

        default:
            printf("Parent process exiting before child process\n");
    }

    return 0;
}


/*
============================================================================
INPUT:
"echo Hello World" 17 05

OUTPUT:
Hello World
============================================================================
*/
