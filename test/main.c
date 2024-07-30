/* test/main.c */
#include "../main.h"

int main(void)
{
    _printf("Character: %c\n", 'H');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percent: %%\n");
    _printf("Integer: %d\n", 12345);
    _printf("Negative Integer: %i\n", -6789);
    _printf("Unknown: %r\n"); /* Should print "%r" */

    return (0);
}

