#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <liburing.h>

#define QUEUE_DEPTH 1
#define READ_SIZE 512

int main() {
    struct io_uring ring;
    struct io_uring_sqe *sqe;
    struct io_uring_cqe *cqe;
    int ret;
    int fd;
    char buffer[READ_SIZE];

    // 1. Open the file (regular file descriptor)
    fd = open("testfile.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // 2. Initialize io_uring
    ret = io_uring_queue_init(QUEUE_DEPTH, &ring, 0);
    if (ret < 0) {
        fprintf(stderr, "io_uring_queue_init: %s\n", strerror(-ret));
        return 1;
    }

    // 3. Get a submission queue entry
    sqe = io_uring_get_sqe(&ring);
    if (!sqe) {
        fprintf(stderr, "io_uring_get_sqe failed\n");
        return 1;
    }

    // 4. Prepare a read operation
    io_uring_prep_read(sqe, fd, buffer, READ_SIZE, 0);

    // 5. Submit the request
    ret = io_uring_submit(&ring);
    if (ret < 0) {
        fprintf(stderr, "io_uring_submit: %s\n", strerror(-ret));
        return 1;
    }

    // 6. Wait for the completion
    ret = io_uring_wait_cqe(&ring, &cqe);
    if (ret < 0) {
        fprintf(stderr, "io_uring_wait_cqe: %s\n", strerror(-ret));
        return 1;
    }

    // 7. Check if the read was successful
    if (cqe->res < 0) {
        fprintf(stderr, "Async read failed: %s\n", strerror(-cqe->res));
    } else {
        printf("Read %d bytes:\n", cqe->res);
        write(STDOUT_FILENO, buffer, cqe->res);
        printf("\n");
    }

    // 8. Mark the completion entry as seen
    io_uring_cqe_seen(&ring, cqe);

    // 9. Clean up
    io_uring_queue_exit(&ring);
    close(fd);

    return 0;
}
