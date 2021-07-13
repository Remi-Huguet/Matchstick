/*
** EPITECH PROJECT, 2021
** g
** File description:
** g
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

#include "lib_csfml.h"

typedef struct pic
{
    sfTexture *button;
    sfSprite *button1;
    sfSprite *button2;
    sfSprite *button3;
    sfSprite *button4;
    sfTexture *plus;
    sfSprite *plus1;
    sfSprite *plus2;
    sfTexture *moins;
    sfSprite *moins1;
    sfSprite *moins2;
    sfTexture *fond;
    sfSprite *fond1;
    sfTexture *play;
    sfSprite *play1;
    sfFont *txt;
    sfText *txt_lines;
    sfText *txt_coup;
    sfText *lines1;
    sfText *coup1;
    sfText *big;
    sfText *my_turn;
    sfText *remain;
    sfText *perline;
    sfText *ai_turn;
    sfText *part1;
    sfText *part2;
    sfText *part3;
    sfText *part4;
}pic_t;

typedef struct stick
{
    int lines;
    int coup;
    int game2;
    char **map;
    int turn;
    int line;
    int matches;
    sfClock *clock;
    sfTime time;
    float second;
    int win;
    int ai_line;
    int ai_matches;
}stick_t;

void game(sfRenderWindow *window, stick_t *stick, pic_t *pic, sfVector2i aim);
int no_stick_line(char *str);
int no_stick_map(char **map);
int one_stick(char a, int *nb);
int basic_turn(char **map, int *i, int *y);
int how_many_stick(int nb, int *max_stick);
int how_many_stick_re(int nb, int tempo, int max_stick, int ***y);
int ai_turn(char **map, int *end, int max_stick, stick_t *stick);
void edit_map(char **map, int i, int y);
void draw_plus_moins(sfRenderWindow *window, pic_t *pic);
void draw_map(sfRenderWindow *window, stick_t *stick, pic_t *pic);
char **get_map(int i);
void menu(sfRenderWindow *window, pic_t *pic, stick_t *stick, sfVector2i aim);
void draw_plus_moins(sfRenderWindow *window, pic_t *pic);
char *increase_score(char *char_score, int int_score);
void init_pictures(pic_t *pic);

#endif /* !MATCHSTICK_H */
