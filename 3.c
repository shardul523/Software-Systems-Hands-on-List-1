#include <stdio.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please enter the filename to be created\n");
    }

    const char* filename = argv[1];

    int file = creat(filename, 0644);

    printf("File Descriptor Value: %d\n", file);

    return 0;
}
