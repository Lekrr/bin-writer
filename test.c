#include "bin-writer.h"
#include <stdio.h>

int main(void)
{
    bw_byte_order = BW_LITTLE_ENDIAN;
    printf("Hello world!\n");

    return 0;
}
