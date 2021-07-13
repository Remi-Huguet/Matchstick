/*
** EPITECH PROJECT, 2021
** put
** File description:
** put
*/
#include <unistd.h>
#include "../include/matchstick.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (i);
}

int my_putdoublechar(char **str)
{
    int i = 0;

    while (str[i]) {
        my_putstr(str[i]);
        my_putstr("\n");
        i = i + 1;
    }
    return (0);
}

int print_digit(int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
        return (nb);
    }
    if (nb  < 0) {
        nb = nb * (-1);
    }
    else {
        my_putnbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    return (nb);
}

int my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * - 1;
    }
    print_digit(nb);
    return (0);
}
