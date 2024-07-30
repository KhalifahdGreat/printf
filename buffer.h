#ifndef BUFFER_H
#define BUFFER_H

#include <stdlib.h>
#include <unistd.h>

typedef struct buffer
{
    char *start;
    char *current;
    size_t size;
    size_t len;
} buffer_t;

buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
int _memcpy(buffer_t *output, const char *src, size_t n);

#endif /* BUFFER_H */

