/*
** EPITECH PROJECT, 2021
** ai
** File description:
** ai
*/
#include "../include/matchstick.h"

int one_stick_per_line(char **map)
{
    int i = 1;
    int y = 1;
    int nb = 0;

    while (map[i]) {
        while (map[i][y] != '\0') {
            one_stick(map[i][y], &nb);
            y = y + 1;
        }
        if (nb > 1)
            return (-1);
        nb = 0;
        i = i + 1;
        y = 1;
    }
    return (0);
}

int max_stick_or_less(char **map, int **i, int **y, int max_stick)
{
    int nb = 0;

    while (map[**i]) {
        while (map[**i][**y]) {
            one_stick(map[**i][**y], &nb);
            **y = **y + 1;
        }
        if (nb <= max_stick && nb != 0 && nb != 1) {
            how_many_stick(nb, &max_stick);
            **y = max_stick;
            return (0);
        }
        **i = **i + 1;
        nb = 0;
        **y = 0;
    }
    return (-1);
}

int more_than_max_stick(char **map, int **i, int **y, int max_stick)
{
    int nb = 0;
    int tempo = max_stick;

    while (map[**i]) {
        while (map[**i][**y]) {
            one_stick(map[**i][**y], &nb);
            **y = **y + 1;
        }
        if (nb > max_stick)
            return (how_many_stick_re(nb, tempo, max_stick, &y));
        **i = **i + 1;
        nb = 0;
        **y = 0;
    }
    return (-1);
}

int ai_play(int *i, int *y, char **map, int max_stick)
{
    *i = 1;
    *y = 1;
    while (no_stick_line(map[*i]) == 0)
        *i = *i + 1;
    if (one_stick_per_line(map) == 0)
        return (0);
    *i = 1;
    *y = 1;
    if (more_than_max_stick(map, &i, &y, max_stick) == 0)
        return (0);
    *i = 1;
    *y = 1;
    if (max_stick_or_less(map, &i, &y, max_stick) == 0)
        return (0);
    return (0);
}

int ai_turn(char **map, int *end, int max_stick, stick_t *stick)
{
    stick->ai_line = 0;
    stick->ai_matches = 0;

    if (*end == 0) {
        if (max_stick > 1)
            ai_play(&stick->ai_line, &stick->ai_matches, map, max_stick);
        else
            basic_turn(map, &stick->ai_line, &stick->ai_matches);
        edit_map(map, stick->ai_line, stick->ai_matches);
        if (no_stick_map(map) == 0)
            *end = 2;
    }
    return (0);
}
