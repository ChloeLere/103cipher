/*
** EPITECH PROJECT, 2020
** encrypted_or_decrypted
** File description:
** defiine if encrypted or decrypted
*/

#include "include/my.h"

void encrypted_or_decrypted(char **argv)
{
    if (argv[3][0] == '0')
        encrypted(argv);
    if (argv[3][0] == '1')
        decrypted(argv);
}

int find_size(char **argv)
{
    int size = 3;
    
    if (my_strlen(argv[2]) > 25)
        size = 6;
    if (my_strlen(argv[2]) > 16 && my_strlen(argv[2]) <= 25)
        size = 5;
    if(my_strlen(argv[2]) > 9 && my_strlen(argv[2]) <= 16)
        size = 4;
    if (my_strlen(argv[2]) <= 4)
        size = 2;
    if (my_strlen(argv[2]) == 1)
        size = 1;
    return(size);
}

int encrypted(char **argv)
{
    float **matrix_message;
    float **matrix_key;
    int size = find_size(argv);

    matrix_message = create_matrix_message(argv[1], size);
    matrix_key = create_matrix_key(argv[2], size);
    printf("Key matrix:\n");
    display_matrix(matrix_key, size);
    printf("\nEncrypted message:\n");
    produit_matrice(matrix_key, matrix_message, my_strlen(argv[1]), size);
    free_matrix_key(matrix_key, size);
    free_matrix_message(matrix_message, my_strlen(argv[1]), size);
    return (0);
}

void decrypted(char **argv)
{
    float **matrix_message;
    float **matrix_key;
    int size = 3;

    if (my_strlen(argv[2]) <= 4)
        size = 2;
    matrix_message = create_matrix_message_d(argv[1], size);
    matrix_key = create_matrix_key(argv[2], size);
    matrix_key = inverse_matrix(matrix_key, size);
    printf("Key matrix:\n");
    if (my_strlen(argv[2]) == 1)
        printf("%d\n", argv[2][0]);
    else
        display_matrix_d(matrix_key, size);
    printf("\nDecrypted message:\n");
    matrix_message = produit_matrice_inv(matrix_key, matrix_message, count(argv[1], size), size);
    free_matrix_key(matrix_key, size);
    free_matrix_message(matrix_message, count(argv[1], size), size);
} 