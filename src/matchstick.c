/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/
#include <stdio.h>
#include "../include/matchstick.h"

int my_turn(char **map, int lgs, int nb, int *end)
{
    int i = 0;
    int y = 0;

    my_putstr("Line: ");
    i = get_i(lgs - 2, map);
    if (i == 284)
        return (284);
    my_putstr("Matches: ");
    y = get_y(nb, i, map, lgs);
    if (y == 284)
        return (284);
    if (y <= nb)
        print_player_msg(map, i, y, &end);
    return (0);
}

int play(char **map, int lgs, int nb)
{
    int end = 0;

    my_putdoublechar(map);
    while (end == 0) {
        my_putstr("\nYour turn:\n");
        if (my_turn(map, lgs, nb, &end) == 284)
            return (0);
        ai_turn(map, &end, nb);
        print_end_msg(end);
    }
    return (end);
}

int matchstick(int ac, char **av)
{
    int lgs;
    char **map;
    int rt = 0;

    if (check_error(ac, av) == 0)
        return (84);
    lgs = my_getnbr(av[1]);
    map = get_map(lgs);
    if (!map)
        return (84);
    rt = play(map, lgs + 2, my_getnbr(av[2]));
    return (rt);
}
