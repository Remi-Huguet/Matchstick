/*
** EPITECH PROJECT, 2021
** include
** File description:
** include
*/
#ifndef MATCHSTICK_H
#define MATCHSTICK_H

int check_error(int ac, char **av);
int get_and_check(char *buffer);
void print_error_line(int *line, int nb, char **map);
int print_error_matches(int line, char **map, int *tab);
int print_ai_msg(int y, int i, char **map);
int print_player_msg(char **map, int i, int y, int **end);
int print_end_msg(int end);
int ai_turn(char **map, int *end, int max_stick);
void edit_map(char **map, int i, int y);
int one_stick(char a, int *nb);
int basic_turn(char **map, int *i, int *y);
int how_many_stick(int nb, int *max_stick);
int how_many_stick_re(int nb, int tempo, int max_stick, int ***y);
void put_stick(char **map, int *tab);
int nb_stick(char *str);
int no_stick_line(char *str);
int my_getnbr(char *str);
int my_strlen(char const *str);
int matchstick(int ac, char **av);
char **get_map(int i);
int no_stick_map(char **map);
int my_turn(char **map, int lgs, int nb, int *end);
int get_i(int nb, char **map);
int get_y(int nb, int x, char **map, int lgs);
int my_putnbr(int nb);
int my_putstr(char const *str);
int my_putdoublechar(char **str);

#endif /* !MATCHSTICK_H */
