/*
** EPITECH PROJECT, 2020
** calc_matr
** File description:
** calc matrix
*/

#include "include/my.h"

void free_matrix_res(float **matrix_res, int i)
{
    int x = 0;

    for (x = 0; x < i; x++) {
        free(matrix_res[x]);
    }
    free(matrix_res);
}

int nbr_div(int size, int nbr)
{
    int t = size / nbr;

    if (nbr == 2) {
        if (size % 2 > 0)
            t++;
    }
    if (nbr == 3) {
        if (size % 3 > 0)
            t++;
    }
    return (t);
}

void produit_matrice(float **matrix_key, float **matrix_message, int size, int nbr)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int t = nbr_div(size, nbr);
    float temp = 0;
    float **matrix_res = malloc(sizeof(float *) * (t + 1));

    for (i = 0; i < t; i++) {
        matrix_res[i] = malloc(sizeof(float) * (nbr + 1));
        for (j = 0; j < nbr; j++) {
            for (k = 0; k < nbr; k++) {
                temp += matrix_message[i][k] * matrix_key[k][j];
            }
            matrix_res[i][j] = temp;
            temp = 0;
        }
    }
    display_matrix_res(matrix_res, i, nbr);
    free_matrix_res(matrix_res, i);
}