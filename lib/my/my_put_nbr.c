/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** put nbr simple and unsigned
*/

#include "my.h"

int my_put_nbr(int nb)
{
    long n = nb;

    if (n < 0) {
        n = n * (-1);
        my_putchar('-');
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
    }
    my_putchar((n % 10) + '0');
}

int my_put_nbr_unsigned(int nb)
{
    unsigned int n = nb;

    if (n > 9) {
        my_put_nbr_unsigned(n / 10);
        n = nb % 10;
    }
    if (n < 10) {
        my_putchar(n + '0');
    }
}