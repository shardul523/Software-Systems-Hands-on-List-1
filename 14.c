/*
============================================================================
Name : 14.c

Author : Shardul Sisodiya

Description :
Write a program to find the type of a file.
    a. Input should be taken from command line.
    b. program should be able to identify any type of a file.

Date: 28th Aug, 2024.
============================================================================
*/


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    char filename[100];
    char inputPrompt[] = "Please enter the file name of which the type is to be discerned: ";
    struct stat file_stats;

    write(1, inputPrompt, sizeof(inputPrompt));
    int fname_size = read(0, filename, 99);

    if (fname_size < 0) {
        perror("Please provide a file name as input");
        return 1;
    }

    filename[fname_size - 1] = 0;

    if (lstat(filename, &file_stats) != 0) {
        perror("There was some error in reading the file's stats");
        return 1;
    }

    mode_t ft = file_stats.st_mode;

    printf("The type of the given file is ");

    if (S_ISREG(ft)) {
        printf("Regular file");
    } else if (S_ISBLK(ft)) {
        printf("Block Device");
    } else if (S_ISCHR(ft)) {
        printf("Character Device");
    } else if (S_ISDIR(ft)) {
        printf("Directory");
    } else if (S_ISFIFO(ft)) {
        printf("FIFO file");
    } else if (S_ISSOCK(ft)) {
        printf("Socket file");
    } else if (S_ISLNK(ft)) {
        printf("Symbolic link");
    } else {
        printf("not identifiable");
    }

    printf(".\n");

    return 0;
}

/*
============================================================================
INPUT:
Please enter the file name of which the type is to be discerned: sample.txt

OUTPUT:
The type of the given file is Regular file.
============================================================================
*/
