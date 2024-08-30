// NAME - SHARDUL SISODIYA
// ROLL NO - MT2024140

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char* buffer = calloc(100, sizeof(char));
    ssize_t bytes_read;

    bytes_read = read(0, buffer, 99);

    if (write(1, buffer, bytes_read) == -1) {
        printf("\nSomething broke!\n");
        return 1;
    }

    printf("\nRead from STDIN and prints to STDOUT\n");

    return 0;
}
