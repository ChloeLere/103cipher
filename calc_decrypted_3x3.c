/*
** EPITECH PROJECT, 2020
** calc_decripted_3x3
** File description:
** calc for 3x3 matrix
*/

#include "include/my.h"

float **transp_m(float **matrix)
{
    int x = 0;
    int y = 0;
    float **matrix_res = malloc(sizeof(float *) * (4));

    for (x = 0; x < 3; x++) {
        matrix_res[x] = malloc(sizeof(float) * 4);
        for (y = 0; y < 3; y++)
            matrix_res[x][y] = matrix[y][x];
    }
    free_matrix_key(matrix, 3);
    return (matrix_res);
}

float **comatrice(float **matrix)
{
    int x = 0;
    float **matrix_res = malloc(sizeof(float *) * (4));

    for (x = 0; x < 3; x++)
        matrix_res[x] = malloc(sizeof(float) * 4);
    matrix_res[0][0] = + (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
    matrix_res[0][1] = - (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
    matrix_res[0][2] = + (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
    matrix_res[1][0] = - (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
    matrix_res[1][1] = + (matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2]);
    matrix_res[1][2] = - (matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]);
    matrix_res[2][0] = + (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]);
    matrix_res[2][1] = - (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
    matrix_res[2][2] = + (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
    free_matrix_key(matrix, 3);
    return (matrix_res);
}

int determinant(float **matrix)
{
    int d = (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
    (matrix[0][1] * matrix[1][2] * matrix[2][0]) +
    (matrix[0][2] * matrix[1][0] * matrix[2][1]) -
    (matrix[0][2] * matrix[1][1] * matrix[2][0]) -
    (matrix[0][1] * matrix[1][0] * matrix[2][2]) -
    (matrix[0][0] * matrix[1][2] * matrix[2][1]);

    return (d);
}