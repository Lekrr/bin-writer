#ifndef ERR_H
#define ERR_H

#include <stdio.h>

#define COLOR_RED   "\x1b[31m"
#define COLOR_RESET "\x1b[0m"

#define ERR_LOG(format, ...) \
    fprintf(stderr, "[%s:%d] " COLOR_RED "error: " COLOR_RESET  format, __FILE__, __LINE__, __VA_ARGS__);\

#endif /* ERR_H */
