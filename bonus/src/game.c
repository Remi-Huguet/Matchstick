/*
** EPITECH PROJECT, 2021
** d
** File description:
** f
*/
#include "../include/lib_csfml.h"
#include "../include/matchstick.h"
#include <stdlib.h>

int max_stick_line(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == '|')
            nb = nb + 1;
        i = i + 1;
    }
    return (nb);
}

void increase_value(sfVector2i aim, stick_t *stick)
{
    int a = 0;

    if (aim.x > 1700 && aim.x < 1750 && aim.y > 450 && aim.y < 500 && stick->line > 1) {
        a = stick->line;
        stick->line = stick->line - 1;
        if (no_stick_line(stick->map[stick->line]) == 0) {
            while (no_stick_line(stick->map[stick->line]) == 0 && stick->line > 0)
                stick->line = stick->line - 1;
            if (stick->line == 0)
                stick->line = a;
        }
            
    }
    if (aim.x > 1800 && aim.x < 1850 && aim.y > 450 && aim.y < 500 && stick->line < stick->lines) {
        a = stick->line;
        stick->line = stick->line + 1;
        if (no_stick_line(stick->map[stick->line]) == 0) {
            while (stick->map[stick->line] != NULL && no_stick_line(stick->map[stick->line]) == 0)
                stick->line = stick->line + 1;
            if (!stick->map[stick->line])
                stick->line = a;
        }
    }   
    if (aim.x > 1700 && aim.x < 1750 && aim.y > 550 && aim.y < 600 && stick->matches > 1)
        stick->matches = stick->matches - 1;
    if (aim.x > 1800 && aim.x < 1850 && aim.y > 550 && aim.y < 600 && stick->matches < stick->coup && stick->matches < max_stick_line(stick->map[stick->line]))
        stick->matches = stick->matches + 1;
}

void my_turn(sfRenderWindow *window, sfVector2i aim, stick_t *stick, pic_t *pic)
{
    char *char_line = malloc(sizeof(char) * 10);
    char *char_matches= malloc(sizeof(char) * 10);
    int a = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft))
        increase_value(aim, stick);
    increase_score(char_line, stick->line);
    increase_score(char_matches, stick->matches);
    sfText_setString(pic->lines1, char_line);
    sfText_setString(pic->coup1, char_matches);
    draw_plus_moins(window, pic);
    sfRenderWindow_drawSprite(window, pic->play1, NULL);
    sfRenderWindow_drawText(window, pic->my_turn, NULL);
    sfRenderWindow_drawText(window, pic->remain, NULL);
    sfRenderWindow_drawText(window, pic->part1, NULL);
    sfRenderWindow_drawText(window, pic->part2, NULL);
    sfRenderWindow_drawText(window, pic->part3, NULL);
    sfRenderWindow_drawText(window, pic->part4, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (aim.x > 1530 && aim.x < 1700 && aim.y > 700 && aim.y < 870) {
            stick->turn = 1;
            edit_map(stick->map, stick->line, stick->matches);
            if (no_stick_map(stick->map) == 0)
                stick->win = 1;
            for (int i = 0; stick->map[i] && a == 0; i = i + 1)
                if (no_stick_line(stick->map[i]) == -1) {
                    stick->line = i;
                    a = 1;
                }
            stick->matches = 1;
            stick->second = 0;
            sfClock_restart(stick->clock);
        }
    free(char_line);
    free(char_matches);
}

void ennemie_turn(sfRenderWindow *window, stick_t *stick, pic_t *pic)
{
    stick->time = sfClock_getElapsedTime(stick->clock);
    stick->second = stick->time.microseconds / 1000000.0;
    if (stick->second > 0 && stick->second <= 1)
        sfText_setString(pic->ai_turn, ".");
    else if (stick->second > 1 && stick->second <= 2)
        sfText_setString(pic->ai_turn, "..");
    else
        sfText_setString(pic->ai_turn, "...");
    sfRenderWindow_drawText(window, pic->ai_turn, NULL);
    sfRenderWindow_drawText(window, pic->remain, NULL);
    if (stick->second > 3) {
        ai_turn(stick->map, &stick->win, stick->coup, stick);
        sfText_setString(pic->part1, "AI removed ");
        char *aaa = malloc(sizeof(char) * 10);
        aaa = increase_score(aaa, stick->ai_matches);
        sfText_setString(pic->part2, aaa);
        aaa = increase_score(aaa, stick->ai_line);
        sfText_setString(pic->part3, "matches from line ");
        sfText_setString(pic->part4, aaa);
        free(aaa);
        stick->turn = 0;
        sfClock_restart(stick->clock);
    }
}

void end(sfRenderWindow *window, stick_t *stick, pic_t *pic)
{
    sfVector2f mid = {700, 400};

    stick->time = sfClock_getElapsedTime(stick->clock);
    stick->second = stick->time.microseconds / 1000000.0;
    if (stick->win == 1) {
        if (stick->second > 0 && stick->second <= 2) {
            sfText_setCharacterSize(pic->ai_turn, 120);
            sfText_setString(pic->ai_turn, "You lose ");
            sfText_setPosition(pic->ai_turn, mid);
            sfRenderWindow_drawText(window, pic->ai_turn, NULL);
        } else
            stick->win = -1;
    }
    if (stick->win == 2) {
        if (stick->second > 0 && stick->second <= 2) {
            sfText_setCharacterSize(pic->ai_turn, 120);
            sfText_setString(pic->ai_turn, "You win");
            sfText_setPosition(pic->ai_turn, mid);
            sfRenderWindow_drawText(window, pic->ai_turn, NULL);
        } else
            stick->win = -2;
    }
}

void game(sfRenderWindow *window, stick_t *stick, pic_t *pic, sfVector2i aim)
{
    if (stick->win == 0)
        draw_map(window, stick, pic);
    if (stick->turn == 0 && stick->win == 0)
        my_turn(window, aim, stick, pic);
    if (stick->turn == 1 && stick->win == 0)
        ennemie_turn(window, stick, pic);
    if (stick->win == 1 || stick->win == 2)
        end(window, stick, pic);
}
