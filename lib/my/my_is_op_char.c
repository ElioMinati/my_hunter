/*
** EPITECH PROJECT, 2021
** my_is_op_char.c
** File description:
** verify if char is operator
*/

int my_is_op_char(char c)
{
    if (c  == '+' || c == '-' || c == '/' || c == '%' || c == '*')
        return (1);
    return (0);
}
