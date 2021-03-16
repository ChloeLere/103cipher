/*
** EPITECH PROJECT, 2020
** calc_decripted_2x2
** File description:
** calc for 2x2 matrix
*/

#include "include/my.h"

float **transpose_2(float **matrix)
{
    int x = 0;
    int y = 0;
    float **matrix_res = malloc(sizeof(float *) * (3));

    for (x = 0; x < 2; x++) {
        matrix_res[x] = malloc(sizeof(float) * 3);
        for (y = 0; y < 2; y++)
            matrix_res[x][y] = matrix[y][x];
    }
    free_matrix_key(matrix, 2);
    return (matrix_res);
}

float **comatrice2(float **matrix)
{
    int x = 0;
    float **matrix_res = malloc(sizeof(float *) * (3));

    for (x = 0; x < 2; x++)
        matrix_res[x] = malloc(sizeof(float) * 3);
    matrix_res[0][0] = matrix[1][1];
    matrix_res[0][1] = - matrix[1][0];
    matrix_res[1][0] = - matrix[0][1];
    matrix_res[1][1] = matrix[0][0];
    free_matrix_key(matrix, 2);
    return (matrix_res);
}

int determinant2(float **matrix)
{
    int d = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    return (d);
}