#include "bin-writer.h"

#include "buf.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include <unistd.h>
#include <errno.h>

enum BW_BYTE_ORDER bw_byte_order = BW_LITTLE_ENDIAN;

static int write_buf(const int fd, const buf_t *buf) {
    char *data = buf->buf;
    ssize_t n, offset = 0;
    while ((n = write(fd, data + offset, buf->size - offset)) != 0) {
        if (n == -1) {
            exit(errno);
        }
        offset += n;
    }
    return offset != buf->size;
}

int bin_write(const int fd, const char *format, ...) {
    va_list args;
    va_start(args, format);

    buf_t buf = {};

    while (*format != '\0') {
        if (*format == '%') {
            if (*(format + 1) == '\0') {
                // TODO: do something
            }
            switch (*(format + 1)) {
                case 'd': {
                    int arg = va_arg(args, int);
                    buf_push_int(&buf, arg);
                    format++;
                    break;
                }
                case 'u': {
                    unsigned int arg = va_arg(args, unsigned int);
                    buf_push_uint(&buf, arg);
                    break;
                }
            } 
        } else {
            buf_push_char(&buf, *format);           
        }
        format++;
    }

    write_buf(fd, &buf);

    va_end(args);
    return 0;
}

int bin_read(const int fd, const char *format, ...) {
    va_list args;
    va_start(args, format);

    char *buf = NULL;

    va_end(args);
    return 0;
}
