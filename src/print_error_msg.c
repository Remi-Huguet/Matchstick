/*
** EPITECH PROJECT, 2021
** print_error_msg
** File description:
** print_error_msg
*/
#include "../include/matchstick.h"

void print_error_line(int *line, int nb, char **map)
{
    if (*line != -1) {
        if (*line > nb || *line == 0) {
            my_putstr("Error: this line is out of range\nLine: ");
            *line = -1;
        } else if (no_stick_line(map[*line]) == 0) {
            my_putstr("Error: not enough matches on this line\nLine: ");
            *line = -1;
        }
    }
}

int too_much(int *line, char **map, int *tab)
{
    int end = 0;

    if (*line > tab[2]) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(tab[2]);
        my_putstr(" matches per turn\n");
        if (my_turn(map, tab[1], tab[2], &end) == 284)
            return (284);
        *line = -1;
    }
    return (0);
}

int print_error_matches(int line, char **map, int *tab)
{
    int end = 0;

    if (too_much(&line, map, tab) == 284)
        return (284);
    if (line == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        if (my_turn(map, tab[1], tab[2], &end) == 284)
            return (284);
        line = -1;
    }
    if (line > nb_stick(map[tab[0]])) {
        my_putstr("Error: not enough matches on this line\n");
        if (my_turn(map, tab[1], tab[2], &end) == 284)
            return (284);
        line = -1;
    }
    return (0);
}
