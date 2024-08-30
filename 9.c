// NAME - SHARDUL SISODIYA
// ROLL NO - MT2024140

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
    printf("Last access Time: %s\n", ctime(&fileStat.st_atim.tv_sec));
    printf("Last modified Time: %s\n", ctime(&fileStat.st_mtim.tv_sec));
    printf("Last change Time: %s\n", ctime(&fileStat.st_ctim.tv_sec));

    return 0;
}
