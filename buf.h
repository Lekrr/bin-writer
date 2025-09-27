#ifndef BUF_H
#define BUF_H

typedef struct __BUF
{
    char *buf;
    int size;
    int capacity;
} buf_t;

buf_t *new_buf(void);

void buf_push(buf_t *buf, const char *data, const int size);

void buf_push_char(buf_t *buf, const char c);

void buf_push_int(buf_t *buf, const int num);
void buf_push_uint(buf_t *buf, const unsigned int num);

void free_buf(buf_t *buf);

#endif
