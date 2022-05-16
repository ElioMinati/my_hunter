/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** print number passed as arg
*/

#include <stdlib.h>

char *int_to_str(int nb);

int my_putstr(char const *str);

void my_put_nbr(int nb)
{
    char *str = malloc(14 * sizeof(char));

    str = int_to_str(nb);
    my_putstr(str);
}
