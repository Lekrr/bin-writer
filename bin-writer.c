#include "bin-writer.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

enum BW_BYTE_ORDER bw_byte_order = BW_LITTLE_ENDIAN;

int bin_write(const int fd, const char *format, ...) {
    va_list args;
    va_start(args, format);

    char *buf = NULL;

    va_end(args);
    return 0;
}
