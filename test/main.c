/* test/main.c */
#include "../main.h"

int main(void)
{
    int a = 12345;
    long int b = 1234567890L;
    short int c = 123;
    unsigned int ua = 12345;
    unsigned long int ub = 1234567890UL;
    unsigned short int uc = 123;

    _printf("Character: %c\n", 'H');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percent: %%\n");
    _printf("Integer: %d\n", a);
    _printf("Negative Integer: %i\n", -6789);
    _printf("Unsigned: %u\n", ua);
    _printf("Octal: %o\n", ua);
    _printf("Hex (lowercase): %x\n", ua);
    _printf("Hex (uppercase): %X\n", ua);
    _printf("Special String: %S\n", "Best\nSchool"); /* Should print "Best\\x0ASchool" */
    _printf("Pointer: %p\n", (void *)&a); /* Should print the address of a */
    _printf("Unknown: %r\n"); /* Should print "%r" */

    /* Test cases for flag characters */
    _printf("Plus flag with positive integer: %+d\n", 12345);
    _printf("Plus flag with negative integer: %+d\n", -12345);
    _printf("Space flag with positive integer: % d\n", 12345);
    _printf("Space flag with negative integer: % d\n", -12345);
    _printf("Hash flag with octal: %#o\n", 12345);
    _printf("Hash flag with hex (lowercase): %#x\n", 12345);
    _printf("Hash flag with hex (uppercase): %#X\n", 12345);

    /* Test cases for length modifiers */
    _printf("Long integer: %ld\n", b);
    _printf("Short integer: %hd\n", c);
    _printf("Unsigned long integer: %lu\n", ub);
    _printf("Unsigned short integer: %hu\n", uc);
    _printf("Octal long integer: %lo\n", ub);
    _printf("Octal short integer: %ho\n", uc);
    _printf("Hex (lowercase) long integer: %lx\n", ub);
    _printf("Hex (lowercase) short integer: %hx\n", uc);
    _printf("Hex (uppercase) long integer: %lX\n", ub);
    _printf("Hex (uppercase) short integer: %hX\n", uc);

    return (0);
}

