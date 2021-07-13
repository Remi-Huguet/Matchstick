/*
** EPITECH PROJECT, 2021
** get_map
** File description:
** get_map
*/
#include <stdlib.h>
#include <stddef.h>
#include "../include/matchstick.h"

void edit_map(char **map, int i, int y)
{
    int x = 0;

    while (map[i][x] != '\0')
        x = x + 1;
    while (map[i][x] != '|')
        x = x - 1;
    while (y > 0 && x > 0) {
        map[i][x] = ' ';
        x = x - 1;
        y = y - 1;
    }
}

void fill_map(char **map, int i, int cls, int y)
{
    if (i == 0 || i == cls - 1)
        map[y][i] = '*';
    else
        map[y][i] = ' ';
}

void init_map(char **map, int lgs, int cls)
{
    int i = 0;
    int y = 1;

    while (i < cls) {
        map[0][i] = '*';
        map[lgs - 1][i] = '*';
        i = i + 1;
    }
    map[0][i] = '\0';
    map[lgs - 1][i] = '\0';
    while (y < lgs - 1) {
        for (i = 0; i < cls; i = i + 1)
            fill_map(map, i, cls, y);
        map[y][i] = '\0';
        y = y + 1;
    }
}

void get_stick(char **map, int lgs, int cls)
{
    int i = lgs;
    int y = 1;
    int x = y;
    int tab[4] = {0};

    while (i > 0) {
        while (x < cls - 1) {
            tab[0] = x;
            tab[1] = y;
            tab[2] = cls;
            tab[3] = i;
            put_stick(map, tab);
            x = x + 1;
        }
        y = y + 1;
        x = 1;
        i = i - 1;
    }
}

char **get_map(int i)
{
    char **map = malloc(sizeof(char *) * (i + 2));
    int cls = (i - 1) * 2 + 3;
    int y = 0;

    if (!map)
        return (NULL);
    while (y < i + 2) {
        map[y] = malloc(sizeof(char) * cls);
        if (!map[y])
            return (NULL);
        y = y + 1;
    }
    map[y] = NULL;
    init_map(map, i + 2, cls);
    get_stick(map, i, cls);
    return (map);
}
