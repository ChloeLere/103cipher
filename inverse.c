/*
** EPITECH PROJECT, 2020
** inverse
** File description:
** calc inverse key matrix
*/

#include "include/my.h"

float **create_matrix_message_d(char *argv, int size)
{
    int len = my_strlen(argv);
    float **matrix = malloc(sizeof(float *) * ((len / size) + 1));
    int y = 0;
    int c = 0;
    int x = 0;
    int temp = 0;
    
    for (; argv[c] != '\0'; x++) {
        matrix[x] = malloc(sizeof(float) * (size + 1));
        for (y = 0; y < size; y++) {
            if (argv[c] == '\0') {
                matrix[x][y] = 0;
                break;
            }
            temp = my_getnbr_with_i(argv, c);
            for (; argv[c] >= '0' && argv[c] <= '9' && argv[c + 1] != '\0'; c++);
            c++;
            matrix[x][y] = temp;
            temp = 0;
        }
    }
    return (matrix);
}

int count(char *argv, int size)
{
    int y = 0;
    int c = 0;
    int x = 0;
    
    for (; argv[c] != '\0'; x++) {
        for (y = 0; y < size; y++) {
            if (argv[c] == '\0') {
                break;
            }
            for (; argv[c] >= '0' && argv[c] <= '9' && argv[c + 1] != '\0'; c++);
            c++;
        }
    }
    return (x);
}

float **produit_matrice_inv(float **matrix_key, float **matrix_message, int size, int nbr)
{
    int i = 0;
    int j = 0;
    int k = 0;
    float temp = 0;
    float **matrix_res = malloc(sizeof(float *) * (size + 1));

    for (i = 0; i < size; i++) {
        matrix_res[i] = malloc(sizeof(float) * (nbr + 1));
        for (j = 0; j < nbr; j++) {
            for (temp = 0, k = 0; k < nbr; k++) {
                if (matrix_key[k][j] == -0.00000)
                    matrix_key[k][j] = 0.0;
                temp += (matrix_message[i][k] * matrix_key[k][j]);
            }
            if (temp > 31 && temp < 127) {
            my_putchar(temp);
            }
        }
    }
    printf("\n");
    free_matrix_message(matrix_message, size, nbr);
    return (matrix_res);
}

float **inverse_matrix(float **matrix, int size)
{
    int deter = 0;
    float **matrix_res = malloc(sizeof(float *) * (size));
    int x = 0;
    int y = 0;
    
    if (size == 3) {
        deter = determinant(matrix);
        matrix = comatrice(matrix);
        matrix = transp_m(matrix);
    } else {
        deter = determinant2(matrix);
        matrix = comatrice2(matrix);
        matrix = transpose_2(matrix);
    }
    for (x = 0; x < size; x++) {
        matrix_res[x] = malloc(sizeof(float) * size);
        for (y = 0; y < size; y++) {
            matrix_res[x][y] = (1.0 / deter) * matrix[x][y];
        }
    }
    free_matrix_key(matrix, size);
    return (matrix_res);
}