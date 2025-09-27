#ifndef BUF_H
#define BUF_H

typedef struct __BUF
{
    char *buf;
    int size;
    int capacity;
} buf_t;

buf_t *new_buf(void);

void buf_push(buf_t *buf, const void *data, const int size, const int react_to_byte_order);

void buf_push_char(buf_t *buf, const char c);

void free_buf(buf_t *buf);

#endif
