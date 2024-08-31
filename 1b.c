/*
============================================================================
Name : 1b.c

Author : Shardul Sisodiya

Description :
Create the following types of a files using (i) shell command (ii) system call
    b. hard link (link system call)

Date: 8th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <target_path> <link_path>\n", argv[0]);
        return 1;
    }

    if (link(argv[1], argv[2]) == 0) {
        printf("Hard link created\n");
        return 0;
    }

    perror("Hard link could not be created");

    return 1;
}

/*
============================================================================
OUTPUT:
Hard link created
============================================================================
*/
