/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** task03
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i;
    char temp;

    while (str[i] != '\0')
        i++;
    for (int y = 0; i != y; y++) {
        i--;
        temp = str[i];
        str[i] = str[y];
        str[y] = temp;
    }
    return (str);
}
