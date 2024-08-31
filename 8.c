/*
============================================================================
Name : 8.c

Author : Shardul Sisodiya

Description :
Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.

Date: 22nd Aug, 2024.
============================================================================
*/


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    // If the file to be read is not specified
    if (argc == 1) {
        perror("Please specify the file to be read line by line.");
        return 1;
    }

    // Declaring the buffers to be used for storing the input and lines
    char readBuff[100] = {0};
    char lineBuff[10][100] = {0};

    // Declaring the pointers for the line buffer
    int line_no = 0;
    int k = 0;

    // open the file
    int fd = open(argv[1], O_RDONLY);

    // In case the file specified does not exist
    if (fd == -1) {
        perror("Not a valid file to be read\n");
        return 1;
    }

    ssize_t bytes_read = read(fd, readBuff, 99);

    while (bytes_read > 0) {
        for (int i = 0; i < bytes_read; i++) {
            if (readBuff[i] == '\n') {
                lineBuff[line_no++][k] = 0;
                k = 0;
            } else {
                lineBuff[line_no][k++] = readBuff[i];
            }
        }

        bytes_read = read(fd, readBuff, 99);
    }

    char ch;

    for (int i = 0; i < line_no; i++) {
        printf("Line %d: %s", i + 1, lineBuff[i]);
        scanf("%c", &ch);
    }

    close(fd);

    return 0;
}

/*
============================================================================
OUTPUT:
Line 1: This is the first line
Line 2: This is the second line
Line 3: This is the third line
============================================================================
*/
