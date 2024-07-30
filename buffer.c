#include "buffer.h"

/**
 * init_buffer - Initializes a buffer structure.
 *
 * Return: A pointer to the initialized buffer structure.
 */
buffer_t *init_buffer(void)
{
    buffer_t *output;

    output = malloc(sizeof(buffer_t));
    if (output == NULL)
        return (NULL);

    output->size = 1024;
    output->len = 0;
    output->start = malloc(sizeof(char) * output->size);
    if (output->start == NULL)
    {
        free(output);
        return (NULL);
    }

    output->current = output->start;

    return (output);
}

/**
 * free_buffer - Frees a buffer structure.
 * @output: A pointer to the buffer structure.
 */
void free_buffer(buffer_t *output)
{
    free(output->start);
    free(output);
}

/**
 * _memcpy - Copies memory from a source to a buffer structure.
 * @output: A pointer to the buffer structure.
 * @src: A pointer to the source memory.
 * @n: The number of bytes to copy.
 *
 * Return: The number of bytes copied.
 */
int _memcpy(buffer_t *output, const char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n; i++)
    {
        if (output->len == output->size)
        {
            write(1, output->start, output->len);
            output->len = 0;
            output->current = output->start;
        }

        *(output->current) = *(src + i);
        output->current++;
        output->len++;
    }

    return (n);
}

