// NAME - SHARDUL SISODIYA
// ROLL NO - MT2024140

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void) {
    int num_files = 5;
    for (int i = 1; i <= num_files; i++) {
        char* index = (char*)calloc(2, sizeof(char));
        index[0] = '0' + i;
        index[1] = 0;
        char filename[10] = "file";
        strcat(filename, index);
        int fd = creat(filename, 0644);
        if (fd == -1) {
            printf("%s could not be created", filename);
            return 1;
        }
    }

    for(;;);

    return 0;
}
