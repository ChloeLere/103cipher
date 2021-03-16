/*
** EPITECH PROJECT, 2020
** main
** File description:
** main of 103cipher
*/

#include "include/my.h"

int display_h(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_printf("USAGE\n");
        my_printf("    ./103cipher");
        my_printf(" message key flag\n");
        my_printf("\n");
        my_printf("DESCRIPTION\n");
        my_printf("   message       a message, made of ASCII");
        my_printf(" characters\n");
        my_printf("   key           the encryption key, ");
        my_printf("made of ASCII characters\n");
        my_printf("   flag          0 for the message ");
        my_printf("to be encrypted, 1 to be decrypted\n");
        return (1);
    }
    return (0);
}

int error_h(int argc, char **argv)
{
    if (argc == 1)
        return (84);
    if (argc > 4)
        return (84);
    if (argv[1][0] == '-' && argv[1][1] != 'h')
        return (84);
    return (0);
}

int main(int argc, char **argv)
{
    if (error_h(argc, argv) == 84 ) {
        write(2, "Error", 6);
        return (84);
    }
    if (display_h(argv) == 1)
        return (0);
    if (argc < 4 || (argv[3][0] != '0' && argv[3][0] != '1')
    || (argv[3][0] < '0' && argv[3][0] > '1')) {
        write(2, "Error", 6);
        return (84);
    }
    encrypted_or_decrypted(argv);
    return (0);
}