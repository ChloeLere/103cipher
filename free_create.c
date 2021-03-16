/*
** EPITECH PROJECT, 2020
** free_create
** File description:
** create and free matrix
*/

#include "include/my.h"

void free_matrix_key(float **matrix, int nbr)
{
    int x = 0;

    for (; x < nbr; x++)
        free(matrix[x]);
    free(matrix);
}

void free_matrix_message(float **matrix, int size, int nbr)
{
    int x = 0;
    int y = 0;
    int len = size;

    for (len = size, x = 0; len > 0; x++) {
        for (y = 0; y < nbr; y++, len--);
        free(matrix[x]);
    }
    free(matrix);
}

float **create_matrix_message(char *argv, int size)
{
    int len = my_strlen(argv);
    float **matrix = malloc(sizeof(float *) * ((len / size) + 1));
    int y = 0;
    int c = 0;
    int x = 0;

    for (; len > 0; x++) {
        matrix[x] = malloc(sizeof(float) * (size));
        for (y = 0; y < size; y++, c++, len--) {
            if (len > 0)
                matrix[x][y] = argv[c];
            else
                matrix[x][y] = 0;
        }
    }
    return (matrix);
}

float **create_matrix_key(char *argv, int size)
{
    int len = my_strlen(argv);
    float **matrix = malloc(sizeof(float *) * (size));
    int x = 0;
    int y = 0;
    int c = 0;

    for (; x < size; x++) {
        matrix[x] = malloc(sizeof(float) * (size));
        for (y = 0; y < size; y++, c++, len--) {
            if (len > 0)
                matrix[x][y] = argv[c];
            else
                matrix[x][y] = 0;
        }
    }
    return (matrix);
}