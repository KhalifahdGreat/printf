/* test/main.c */
#include "../main.h"

int main(void)
{
    int a = 12345;
    _printf("Character: %c\n", 'H');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percent: %%\n");
    _printf("Integer: %d\n", a);
    _printf("Negative Integer: %i\n", -6789);
    _printf("Unsigned: %u\n", 12345);
    _printf("Octal: %o\n", 12345);
    _printf("Hex (lowercase): %x\n", 12345);
    _printf("Hex (uppercase): %X\n", 12345);
    _printf("Special String: %S\n", "Best\nSchool"); /* Should print "Best\\x0ASchool" */
    _printf("Pointer: %p\n", (void *)&a); /* Should print the address of a */
    _printf("Unknown: %r\n"); /* Should print "%r" */

    return (0);
}

