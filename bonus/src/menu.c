/*
** EPITECH PROJECT, 2021
** g
** File description:
** g
*/
#include "../include/lib_csfml.h"
#include "../include/matchstick.h"
#include <stdlib.h>

void re_init(pic_t *pic, stick_t *stick)
{
    sfVector2f b2 = {1700, 450};
    sfVector2f b1 = {1800, 450};
    sfVector2f b4 = {1700, 550};
    sfVector2f b3 = {1800, 550};
    sfVector2f t1 = {1400, 450};
    sfVector2f t2 = {1580, 450};
    sfVector2f t3 = {1330, 550};
    sfVector2f t4 = {1580, 550};
    sfVector2f t0 = {1450, 250};
    sfVector2f g1 = {1530, 700};

    stick->clock = sfClock_create();
    sfSprite_setPosition(pic->play1, g1);
    sfText_setPosition(pic->my_turn, t0);
    sfSprite_setPosition(pic->button1, b1);
    sfSprite_setPosition(pic->button2, b2);
    sfSprite_setPosition(pic->button3, b3);
    sfSprite_setPosition(pic->button4, b4);
    sfSprite_setPosition(pic->plus1, b1);
    sfSprite_setPosition(pic->plus2, b3);
    sfSprite_setPosition(pic->moins1, b2);
    sfSprite_setPosition(pic->moins2, b4);
    sfText_setString(pic->my_turn, "Your turn :");
    sfText_setString(pic->txt_coup, "Matches :");
    sfText_setPosition(pic->txt_lines, t1);
    sfText_setPosition(pic->lines1, t2);
    sfText_setPosition(pic->txt_coup, t3);
    sfText_setPosition(pic->coup1, t4);
}

void draw_menu(sfRenderWindow *window, pic_t *pic)
{
    sfRenderWindow_drawSprite(window, pic->fond1, NULL);
    sfRenderWindow_drawSprite(window, pic->play1, NULL);
    sfRenderWindow_drawText(window, pic->txt_lines, NULL);
    sfRenderWindow_drawText(window, pic->lines1, NULL);
    sfRenderWindow_drawText(window, pic->txt_coup, NULL);
    sfRenderWindow_drawText(window, pic->coup1, NULL);
    sfRenderWindow_drawText(window, pic->big, NULL);
}

void increase_nb(sfVector2i aim, stick_t *stick)
{
    if (aim.x > 1700 && aim.x < 1750 && aim.y > 500 && aim.y < 550 && stick->lines > 2)
        stick->lines = stick->lines - 1;
    if (aim.x > 1800 && aim.x < 1950 && aim.y > 500 && aim.y < 550 && stick->lines < 14)
        stick->lines = stick->lines + 1;
    if (aim.x > 1700 && aim.x < 1750 && aim.y > 800 && aim.y < 850 && stick->coup > 1)
        stick->coup = stick->coup - 1;
    if (aim.x > 1800 && aim.x < 1850 && aim.y > 800 && aim.y < 850 && stick->coup < (stick->lines - 1) * 2 + 1)
        stick->coup = stick->coup + 1;
}

void menu(sfRenderWindow *window, pic_t *pic, stick_t *stick, sfVector2i aim)
{
    char *char_lines = malloc(sizeof(char) * 10);
    char *char_coup = malloc(sizeof(char) * 10);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        increase_nb(aim, stick);
        if (aim.x > 1530 && aim.x < 1700 && aim.y > 150 && aim.y < 320) {
            stick->game2 = stick->game2 + 1;
            stick->map = get_map(stick->lines);
            re_init(pic, stick);
        }
    }
    increase_score(char_lines, stick->lines);
    increase_score(char_coup, stick->coup);
    sfText_setString(pic->lines1, char_lines);
    sfText_setString(pic->coup1, char_coup);
    draw_menu(window, pic);
    draw_plus_moins(window, pic);
    free(char_lines);
    free(char_coup);
}
