/*
============================================================================
Name : 7.c

Author : Shardul Sisodiya

Description : Write a program to copy file1 into file2 ($cp file1 file2).

Date: 19th Aug, 2024.
============================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char** argv) {
    if (argc < 3) {
        perror("Please provide the path of the target and the destination");
        return 1;
    }

    const char* target = argv[1];
    const char* dest = argv[2];
    char buffer[100] = {0};
    ssize_t bytes_read, bytes_written;

    int target_fd = open(target, O_RDONLY);
    int dest_fd = open(dest, O_CREAT | O_WRONLY, 0644);

    if (target_fd == -1 || dest_fd == -1) {
        perror("\nSome error in the paths specified\n");
        return 1;
    }

    bytes_read = read(target_fd, buffer, sizeof(buffer) - 1);

    while(bytes_read > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);

        if (bytes_written == -1) {
            perror("There was some error in writing the file");
            exit(EXIT_FAILURE);
        }

        bytes_read = read(target_fd, buffer, sizeof(buffer) - 1);
    }

    printf("File copied\n");

    close(target_fd);
    close(dest_fd);

    return 0;
}

/*
============================================================================
OUTPUT:
File copied
============================================================================
*/
