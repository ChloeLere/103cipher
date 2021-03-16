/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "my.h"

int convert(int nb, char *base, int mod)
{
    int res;

    if (nb < 0) {
        nb *= (-1);
        my_putchar('-');
    }
    if (nb >= mod)
        convert(nb / mod, base, mod);
    res = nb % mod;
    my_putchar(base[res]);
    return (0);
}

void my_print_simple(char *type, int i, va_list argv)
{
    if (type[i + 1] == 'd' || type[i + 1] == 'i')
        my_put_nbr(va_arg(argv, int));
    if (type[i + 1] == 's')
        my_putstr(va_arg(argv, char *));
    if (type[i + 1] == 'u')
        my_put_nbr_unsigned(va_arg(argv, unsigned int));
    if (type[i + 1] == 'c')
        my_putchar(va_arg(argv, int));
    if (type[i + 1] == '%')
        my_putchar('%');
}

void my_print_base(char *type, int i, va_list argv)
{
    if (type[i + 1] == 'o')
        convert(va_arg(argv, int), "01234567", 8);
    if (type[i + 1] == 'x')
        convert(va_arg(argv, int), "0123456789abcdef", 16);
    if (type[i + 1] == 'X')
        convert(va_arg(argv, int), "0123456789ABCDEF", 16);
    if (type[i + 1] == 'b')
        convert(va_arg(argv, int), "01", 2);
}

int my_printf_diese(char *type, int i, va_list argv)
{
    if (type[i + 1] == '#') {
        if (type[i + 2] == 'x' || type[i + 2] == 'X') {
            my_putchar('0');
            my_putchar(type[i + 2]);
            return (1);
        }
        if (type[i + 2] == 'o') {
            my_putchar('0');
            return (1);
        }
    }
}

void my_printf(char *type, ...)
{
    int i = 0;
    int size = my_strlen(type);
    va_list argv;

    va_start(argv, type);
    for (; i <= size; i++) {
        if (type[i] == '%') {
            if (type[i + 1] == '#') {
                i += my_printf_diese(type, i, argv);
                my_print_simple(type, i, argv);
                my_print_base(type, i, argv);
                i++;
            } else {
                my_print_simple(type, i, argv);
                my_print_base(type, i, argv);
                i++;
            }
        } else if (type[i] != '\0')
            my_putchar(type[i]);
    }
    va_end(argv);
}