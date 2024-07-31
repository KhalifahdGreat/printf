/* test/main.c */
#include "../main.h"

int main(void)
{
    _printf("Character: %c\n", 'H');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percent: %%\n");
    _printf("Integer: %d\n", 12345);
    _printf("Negative Integer: %i\n", -6789);
    _printf("Unsigned: %u\n", 12345);
    _printf("Octal: %o\n", 12345);
    _printf("Hex (lowercase): %x\n", 12345);
    _printf("Hex (uppercase): %X\n", 12345);
    _printf("Unknown: %r\n"); /* Should print "%r" */

    return (0);
}

