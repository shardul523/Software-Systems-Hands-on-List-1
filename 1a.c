/*
============================================================================
Name : 1a.c

Author : Shardul Sisodiya

Description :
Create the following types of a files using (i) shell command (ii) system call
    a. soft link (symlink system call)
    b. hard link (link system call)
    c. FIFO (mkfifo Library Function or mknod system call)

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

    if (symlink(argv[1], argv[2]) == 0)
        printf("Symbolic link created\n");
    else {
        perror("Symbolic link could not be created");
        return 1;
    }

    return 0;
}


/*
============================================================================
OUTPUT:
Symbolic link created
============================================================================
*/
