/*
** EPITECH PROJECT, 2021
** stick
** File description:
** stick
*/
#include "../include/matchstick.h"

int one_stick(char a, int *nb)
{
    if (a == '|')
        *nb = *nb + 1;
    return (0);
}

int basic_turn(char **map, int *i, int *y)
{
    while (no_stick_line(map[*i]) == 0) {
        *i = *i + 1;
        *y = 1;
    }
    return (0);
}

int how_many_stick(int nb, int *max_stick)
{
    while (nb - *max_stick != 1)
        *max_stick = *max_stick - 1;
    return (0);
}

int how_many_stick_re(int nb, int tempo, int max_stick, int ***y)
{
    while ((nb - tempo) % max_stick != 1) {
        if (nb - tempo == 0) {
            ***y = tempo;
            return (0);
        }
        tempo = tempo - 1;
    }
    ***y = tempo;
    return (0);
}
