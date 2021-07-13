/*
** EPITECH PROJECT, 2021
** get_line
** File description:
** get_line
*/
#include <stdio.h>
#include "../include/matchstick.h"

int get_i(int nb, char **map)
{
    char *buffer = NULL;
    size_t size = 0;
    int i = 0;
    int line = -1;

    while (line == -1) {
        if (getline(&buffer, &size, stdin) == -1)
            return (284);
        line = get_and_check(buffer);
        if (line == -2) {
            my_putstr("Line: ");
            line = -1;
        }
        print_error_line(&line, nb, map);
    }
    return (line);
}

int get_y(int nb, int x, char **map, int lgs)
{
    char *buffer = NULL;
    size_t size = 0;
    int line = -1;
    int tab[3] = {0};
    int end = 0;

    while (line == -1) {
        tab[0] = x;
        tab[1] = lgs;
        tab[2] = nb;
        if (getline(&buffer, &size, stdin) == -1)
            return (284);
        line = get_and_check(buffer);
        if (line == -2)
            my_turn(map, tab[1], tab[2], &end);
        if (print_error_matches(line, map, tab) == 284)
            return (284);
    }
    return (line);
}
