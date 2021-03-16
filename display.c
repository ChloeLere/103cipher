/*
** EPITECH PROJECT, 2020
** display
** File description:
** display matrix
*/

#include "include/my.h"

void display_matrix(float **matrix, int size)
{
    int x = 0;
    int y = 0;

    for (; x < size; x++) {
        for (y = 0; y < size; y++) {
            printf("%.f", matrix[x][y]);
            if (y < (size - 1))
                printf("\t");
        }
        printf("\n");
    }
}

void display_matrix_d(float **matrix, int size)
{
    int x = 0;
    int y = 0;

    for (; x < size; x++) {
        for (y = 0; y < size; y++) {
            if (matrix[x][y] == 0.0000 || matrix[x][y] == -0.0000)
                printf("0.0");
            else
                printf("%.3f", matrix[x][y]);
            if (y < (size - 1))
                printf("\t");
        }
        printf("\n");
    }
}

void display_matrix_res(float **matrix_res, int i, int size)
{
    int k = 0;
    int j = 0;

    for (k = 0; k < i; k++) {
        for (j = 0; j < size; j++) {
            printf("%.f", matrix_res[k][j]);
            if (k < i - 1 || j < size - 1)
                printf(" ");
        }
    }
    printf("\n");
}