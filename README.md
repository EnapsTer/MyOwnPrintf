# MyOwnPrintf
Makefile compile library libftprintf.a, that include function ft_printf().

Prototype:

**int ft_printf(const char s, ...);**

Describe:

- Displays to console symbols like printf(stdio.h) (man printf).

- Realise types: %c, %s, %p, %d, %i, %u, %x and %X

- Realise flags: 0 - *(width) .(precision, works with *).

Return values:

- Number of characters printed or -1, if error.
