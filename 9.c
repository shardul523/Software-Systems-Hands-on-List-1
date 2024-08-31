/*
============================================================================
Name : 9.c

Author : Shardul Sisodiya

Description :
Write a program to print the following information about a given file.
    a. inode
    b. number of hard links
    c. uid
    d. gid
    e. size
    f. block size
    g. number of blocks
    h. time of last access
    i. time of last modification
    j. time of last change

Date: 27th Aug, 2024.
============================================================================
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Use: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) < 0) {
        perror("Stats could not be obtained\n");
        exit(EXIT_FAILURE);
    }

    printf("Information about the file: %s\n", argv[1]);
    printf("Inode Number: %lu\n", fileStat.st_ino);
    printf("Number of Hard Links: %lu\n", fileStat.st_nlink);
    printf("User ID: %u\n", fileStat.st_uid);
    printf("Group ID: %u\n", fileStat.st_gid);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Block Size: %ld bytes\n", fileStat.st_blksize);
    printf("Number of Blocks: %ld\n", fileStat.st_blocks);
    printf("Last access Time: %s", ctime(&fileStat.st_atim.tv_sec));
    printf("Last modified Time: %s", ctime(&fileStat.st_mtim.tv_sec));
    printf("Last change Time: %s", ctime(&fileStat.st_ctim.tv_sec));

    return 0;
}

/*
============================================================================
OUTPUT:
Information about the file: sample.txt
Inode Number: 18088738
Number of Hard Links: 2
User ID: 1000
Group ID: 1000
Size: 70 bytes
Block Size: 4096 bytes
Number of Blocks: 8
Last access Time: Sat Aug 31 12:16:22 2024
Last modified Time: Sat Aug 31 12:16:17 2024
Last change Time: Sat Aug 31 12:16:17 2024
============================================================================
*/
