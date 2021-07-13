/*
** EPITECH PROJECT, 2021
** check_error
** File description:
** check_error
*/
#include <stddef.h>
#include <stdlib.h>
#include "../include/matchstick.h"

int get_and_check(char *buffer)
{
    char *buf = malloc(sizeof(char) * my_strlen(buffer));
    int i = 0;

    while (buffer[i] != '\n') {
        buf[i] = buffer[i];
        i = i + 1;
    }
    buf[i] = '\0';
    i = 0;
    while (buf[i] != '\0') {
        if (buf[i] < 48 || buf[i] > 57) {
            free(buf);
            my_putstr("Error: invalid input (positive number expected)\n");
            return (-2);
        }
        i = i + 1;
    }
    i = my_getnbr(buf);
    free(buf);
    return (i);
}

int check_nb(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 57)
            return (0);
        i = i + 1;
    }
    return (-1);
}

int check_error(int ac, char **av)
{
    if (ac != 3)
        return (0);
    if (check_nb(av[1]) == 0 || check_nb(av[2]) == 0)
        return (0);
    if (my_getnbr(av[2]) <= 0)
        return (0);
    if (my_getnbr(av[1]) > 99 || my_getnbr(av[1]) < 2)
        return (0);
    return (-1);
}
