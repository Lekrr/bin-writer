#include "bin-writer.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("data.bin", O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1) {
        fprintf(stderr, "Failed to open file");
    }

    bin_write(fd, "%d", 1024);

    close(fd);

    return 0;
}
