/*
============================================================================
Name : 18_second.c

Author : Shardul Sisodiya

Description :
Write a program to perform Record locking.
    a. Implement write lock
    b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.

Date: 28th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Record {
    int key;
    int val;
};

void set_read_lock(int fd, int ri) {
    struct flock rlock;

    rlock.l_whence = SEEK_SET;
    rlock.l_start = (ri - 1) * sizeof(struct Record);
    rlock.l_len = sizeof(struct Record);
    rlock.l_type = F_RDLCK;

    if (fcntl(fd, F_SETLK, &rlock) == -1) {
        perror("Could not set up read lock on the record");
        exit(EXIT_FAILURE);
    }

    printf("Read Lock acquired\n");
}

void set_write_lock(int fd, int ri) {
    struct flock wlock;

    wlock.l_whence = SEEK_SET;
    wlock.l_start = (ri - 1) * sizeof(struct Record);
    wlock.l_len = sizeof(struct Record);
    wlock.l_type = F_RDLCK;

    if (fcntl(fd, F_SETLK, &wlock) == -1) {
        perror("Could not set up write lock on the record");
        exit(EXIT_FAILURE);
    }

    printf("Write Lock acquired\n");
}

void unlock(int fd, int ri) {
    struct flock ulock;

    ulock.l_whence = SEEK_SET;
    ulock.l_start = (ri - 1) * sizeof(struct Record);
    ulock.l_len = sizeof(struct Record);
    ulock.l_type = F_RDLCK;

    if (fcntl(fd, F_SETLK, &ulock) == -1) {
        perror("Could not remove the lock on the record");
        exit(EXIT_FAILURE);
    }

    printf("Lock removed\n");
}

void read_record(int fd, int ri) {
    if (lseek(fd, sizeof(struct Record) * (ri - 1), SEEK_SET) == -1) {
        perror("Could not move the cursor to the record");
        exit(EXIT_FAILURE);
    }

    struct Record curr;

    if (read(fd, &curr, sizeof(struct Record)) < 0) {
        perror("Could not read the right record");
        exit(EXIT_FAILURE);
    }

    printf("Key: %d, Value: %d\n", curr.key, curr.val);
}

void update_record(int fd, int ri) {
    struct Record new_rec;
    new_rec.key = ri;

    printf("Enter the new value for record %d: ", ri);
    scanf("%d", &new_rec.val);

    if (lseek(fd, (ri - 1) * sizeof(struct Record), SEEK_SET) == -1) {
        perror("Could not move cursor to update the record");
        exit(EXIT_FAILURE);
    }

    if (write(fd, &new_rec, sizeof(struct Record)) < 0) {
        perror("Could not update the record");
        exit(EXIT_FAILURE);
    }

    printf("Record Updated!\n");
    printf("Key: %d, Value: %d\n", new_rec.key, new_rec.val);
}

int main() {
    int ch;
    int record_num;

    int fd = open("records", O_RDWR);

    if (fd == -1) {
        perror("Could not open the records file");
        exit(EXIT_FAILURE);
    }

    printf("1. Read a record\n");
    printf("2. Update a record\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    if (ch > 2 || ch < 1) {
        perror("Invalid choice");
        exit(EXIT_FAILURE);
    }

    printf("Enter the record you want to access: ");
    scanf("%d", &record_num);

    if (record_num > 3 || record_num < 1) {
        perror("Invalid record number");
        exit(EXIT_FAILURE);
    }

    switch(ch) {
        case 1:
            set_read_lock(fd, record_num);
            read_record(fd, record_num);
            unlock(fd, record_num);
            break;
        case 2:
            set_write_lock(fd, record_num);
            update_record(fd, record_num);
            unlock(fd, record_num);
            break;
        default:
            printf("NOT DEFINED YET\n");
    }

    close(fd);
    return 0;
}

/*
============================================================================
OUTPUT:
1. Read a record
2. Update a record
Enter your choice: 2
Enter the record you want to access: 1
Write Lock acquired
Enter the new value for record 1: 1
Record Updated!
Key: 1, Value: 1
Lock removed
============================================================================
*/
