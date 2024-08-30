// NAME - SHARDUL SISODIYA
// ROLL NO - MT2024140

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

    for (int i = 0; i < line_no - 1; i++) {
        printf("%s", lineBuff[i]);
        scanf("%c", &ch);
    }

    return 0;
}
