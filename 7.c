// NAME - SHARDUL SISODIYA
// ROLL NO - MT2024140

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
    int dest_fd = open(dest, O_CREAT, 0644);

    if (target_fd == -1 || dest_fd == -1) {
        perror("\nSome error in the paths specified\n");
        return 1;
    }

    bytes_read = read(target_fd, buffer, sizeof(buffer) - 1);

    while(bytes_read > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);

        if (bytes_written == -1) {
            perror("\nThere was some error in writing the file\n");
            return 1;
        }

        bytes_read = read(target_fd, buffer, sizeof(buffer) - 1);
    }

    printf("\nFile copied\n");

    close(target_fd);
    close(dest_fd);

    return 0;
}
