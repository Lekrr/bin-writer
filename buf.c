#include "buf.h"

#include "bin-writer.h"

#include <stdlib.h>

buf_t *new_buf(void) {
    buf_t *buf = calloc(1, sizeof(*buf));
    return buf;
}

inline static void buf_size_check(buf_t *buf, int size) {
    if (buf->capacity == 0) {
        buf->capacity = 1;
        buf->buf = calloc(buf->capacity, sizeof(*(buf->buf)));
    }
    if (buf->size + size > buf->capacity) {
        do {
            buf->capacity *= 2;
        } while (buf->size + size > buf->capacity);
        buf->buf = realloc(buf->buf, sizeof(*(buf->buf)));
    }
}

void buf_push_char(buf_t *buf, const char c) {
    buf_size_check(buf, sizeof(c));
    buf->buf[buf->size++] = c;
}

void buf_push(buf_t *buf, const void *data, const int size, const int react_to_byte_order) {
    buf_size_check(buf, size);
    if (react_to_byte_order == 0 /* temporary -> */ || react_to_byte_order == 1) {
        for (int i = 0; i < size; i++) {
            buf->buf[buf->size++] = *((char *) data + i);
        }
    } else {
        // TODO: add implementation for big and little endian
    }
}

void free_buf(buf_t *buf) {
    if (buf == NULL) {
        return;
    }
    if (buf->buf != NULL) {
        free(buf->buf);
    }
    free(buf);
}
