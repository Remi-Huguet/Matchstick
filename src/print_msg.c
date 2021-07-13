/*
** EPITECH PROJECT, 2021
** print_msg
** File description:
** print_msg
*/
#include "../include/matchstick.h"

int print_ai_msg(int y, int i, char **map)
{
    my_putstr("AI removed ");
    my_putnbr(y);
    my_putstr(" match(es) from line ");
    my_putnbr(i);
    my_putstr("\n");
    edit_map(map, i, y);
    my_putdoublechar(map);
    return (0);
}

int print_player_msg(char **map, int i, int y, int **end)
{
    my_putstr("Player removed ");
    my_putnbr(y);
    my_putstr(" match(es) from line ");
    my_putnbr(i);
    my_putstr("\n");
    edit_map(map, i, y);
    my_putdoublechar(map);
    if (no_stick_map(map) == 0)
        **end = 2;
    return (0);
}

int print_end_msg(int end)
{
    if (end == 1)
        my_putstr("I lost... snif but I'll get you next time!!\n");
    else if (end == 2)
        my_putstr("You lost, too bad...\n");
    return (0);
}
