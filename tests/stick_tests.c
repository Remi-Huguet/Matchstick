/*
** EPITECH PROJECT, 2021
** tests
** File description:
** tests
*/
#include "../include/matchstick.h"
#include <criterion/criterion.h>

Test(ia_turn, return_value)
{
    char **map = get_map(2);
    int end = 0;

    cr_assert(ai_turn(map, &end, 2) == 0);
}

Test(check_error, return_value)
{
    char *azert[] = {" ", "fafaezfaz", "5", NULL};
    char *azer[] = {" ", "3", "(ezazr", NULL};
    char *aze[] = {" ", "3", "0", NULL};
    char *az[] = {" ", "1", "3", NULL};
    char *a[] = {" ", "100", "3", NULL};
    char *aa[] = {" ", "3", "3", NULL};

    cr_assert(check_error(2, NULL) == 0);
    cr_assert(check_error(3, azert) == 0);
    cr_assert(check_error(3, azer) == 0);
    cr_assert(check_error(3, aze) == 0);
    cr_assert(check_error(3, az) == 0);
    cr_assert(check_error(3, a) == 0);
    cr_assert(check_error(3, aa) == -1);
}

Test(check_bad_line, return_value)
{
    char *bad_nb = "ang\nn";
    char *bad_nb_re = "(ang\nn";
    char *nb = "4\n";

    cr_assert(get_and_check(bad_nb) == -2);
    cr_assert(get_and_check(bad_nb_re) == -2);
    cr_assert(get_and_check(nb) == 4);
}

Test(basic_fct, return_value)
{
    int i = 1;
    int y = 1;
    int *end = 0;
    char **map = get_map(2);

    cr_assert(print_player_msg(map, i, y, &end) == 0);
    cr_assert(my_getnbr("-+-+1") == 1);
    cr_assert(print_end_msg(0) == 0);
    cr_assert(print_end_msg(1) == 0);
    cr_assert(print_end_msg(2) == 0);
    cr_assert(my_putnbr(-1) == 0);
    cr_assert(my_putnbr(-111) == 0);
}

Test(stick_fct, return_value)
{
    int nb = 0;
    char **map = get_map(2);
    int i = 1;
    int y = 1;
    int max_stick = 7;

    cr_assert(how_many_stick(7, &max_stick) == 0);
    cr_assert(basic_turn(map, &i, &y) == 0);
    cr_assert(one_stick('|', &nb) == 0);
    cr_assert(nb_stick("* ||  *") == 2);
    cr_assert(no_stick_line("*   *") == 0);
}
