#include "buf.h"

#include <stdlib.h>

buf_t *new_buf(void) {
    buf_t *buf = calloc(1, sizeof(*buf));
    return buf;
}

void buf_push_char(buf_t *buf, const char c) {
    if (buf->capacity == 0) {
        buf->capacity = 1;
        buf->buf = calloc(buf->capacity, sizeof(*(buf->buf)));
    }
    if (buf->size == buf->capacity) {
        buf->capacity *= 2;
        buf->buf = realloc(buf->buf, buf->capacity * sizeof(*(buf->buf)));
    } 
    buf->buf[buf->size++] = c;
}

void buf_push(buf_t *buf, const char *data, const int size) {
    if (buf->capacity == 0) {
        buf->capacity = 1;
        buf->buf = calloc(buf->capacity, sizeof(*(buf->buf)));
    }
    if (buf->size + size > buf->capacity) {
        buf->capacity *= 2;
        buf->buf = realloc(buf->buf, sizeof(*(buf->buf)));
    }
    // TODO: add support for both big and little endian
    for (int i = 0; i < size; i++) {
        buf->buf[buf->size++] = *(data + i);
    }
}

void buf_push_int(buf_t *buf, const int num) {
    if (buf->capacity == 0) {
        buf->capacity = 1;
        buf->buf = calloc(buf->capacity, sizeof(*(buf->buf)));
    }
    if (buf->size + sizeof(num) > buf->capacity) {
        buf->capacity *= 2;
        buf->buf = realloc(buf->buf, buf->capacity * sizeof(*(buf->buf)));
    }
    // TODO: add support for both big and little endian
    *(int *) &(buf->buf[buf->size]) = num;
    buf->size += sizeof(num);
}

void buf_push_uint(buf_t *buf, const unsigned int num) {
    if (buf->capacity == 0) {
        buf->capacity = 1;
        buf->buf = calloc(buf->capacity, sizeof(*(buf->buf)));
    }
    if (buf->size + sizeof(num) > buf->capacity) {
        buf->capacity *= 2;
        buf->buf = realloc(buf->buf, buf->capacity * sizeof(*(buf->buf)));
    }
    // TODO: add support for both big and little endian
    *(unsigned *) &(buf->buf[buf->size]) = num;
    buf->size += sizeof(num);
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
