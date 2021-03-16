/*
** EPITECH PROJECT, 2020
** my
** File description:
** functions in libmy.a
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_put_nbr_unsigned(int nb);
int convert(int nb, char *base, int mod);
void my_print_simple(char *type, int i, va_list argv);
void my_print_base(char *type, int i, va_list argv);
int my_printf_diese(char *type, int i, va_list argv);
void my_printf(char *type, ...);
int my_getnbr_with_i(char const *str, int i);

int display_h(char **argv);
int error_h(int argc, char **argv);
float **create_matrix_message(char *argv, int size);
float **create_matrix_key(char *argv, int size);
void display_matrix(float **matrix, int size);
void free_matrix_message(float **matrix, int size, int nbr);
void free_matrix_key(float **matrix, int nbr);
void encrypted_or_decrypted(char **argv);
int encrypted(char **argv);
void decrypted(char **argv);
float **transp_m(float **matrix);
float **comatrice(float **matrix);
int determinant(float **matrix);
float **inverse_matrix(float **matrix, int size);
void free_matrix_res(float **matrix_res, int i);
void display_matrix_res(float **matrix_res, int i, int size);
void produit_matrice(float **matrix_key, float **matrix_message, int size, int nbr);
int determinant_part2(float **matrix);
void display_matrix_d(float **matrix, int size);
float **create_matrix_message_d(char *argv, int size);
int count(char *argv, int size);
float **produit_matrice_inv(float **matrix_key, float **matrix_message, int size, int nbr);
int find_size(char **argv);
float **transpose_2(float **matrix);
float **comatrice2(float **matrix);
int determinant2(float **matrix);
int nbr_div(int size, int nbr);
