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

int check_case(char **map, int i, int y)
{
    if (map[i][y] == '|')
        return (-1);
    return (0);
}

int no_stick_map(char **map)
{
    int i = 0;
    int y = 0;
    int rt = 0;

    while (map[i]) {
        while (map[i][y] != '\0' && rt == 0) {
            rt = check_case(map, i, y);
            y = y + 1;
        }
        if (rt == -1)
            return (-1);
        y = 0;
	i = i + 1;
    }
    return (0);
}

int no_stick_line(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
	if (str[i] == '|')
            return (-1);
	i = i + 1;
    }
    return (0);
}
