#ifndef BIN_WRITER_H
#define BIN_WRITER_H

enum BW_BYTE_ORDER
{
    BW_LITTLE_ENDIAN = 0X1234,
    BW_BIG_ENDIAN    = 0x4321,
};

// Byte order used for reading and writing operations
extern enum BW_BYTE_ORDER bw_byte_order;

int bin_write(const int fd, const char *format, ...);

#endif
