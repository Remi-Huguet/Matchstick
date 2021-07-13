/*
** EPITECH PROJECT, 2021
** gg
** File description:
** g
*/
#include "../include/lib_csfml.h"
#include "../include/matchstick.h"
#include <stdlib.h>

void draw_plus_moins(sfRenderWindow *window, pic_t *pic)
{
    sfRenderWindow_drawSprite(window, pic->button1, NULL);
    sfRenderWindow_drawSprite(window, pic->button2, NULL);
    sfRenderWindow_drawSprite(window, pic->button3, NULL);
    sfRenderWindow_drawSprite(window, pic->button4, NULL);
    sfRenderWindow_drawSprite(window, pic->plus1, NULL);
    sfRenderWindow_drawSprite(window, pic->plus2, NULL);
    sfRenderWindow_drawSprite(window, pic->moins1, NULL);
    sfRenderWindow_drawSprite(window, pic->moins2, NULL);
    sfRenderWindow_drawText(window, pic->txt_lines, NULL);
    sfRenderWindow_drawText(window, pic->lines1, NULL);
    sfRenderWindow_drawText(window, pic->txt_coup, NULL);
    sfRenderWindow_drawText(window, pic->coup1, NULL);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

int nb_stick(char *str)
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

void draw_map(sfRenderWindow *window, stick_t *stick, pic_t *pic)
{
    int i = 0;
    int nb_pixel = 7;
    int tempo;
    int x = 910 - (my_strlen(stick->map[i]) * nb_pixel);
    sfVector2f big1 = {x, 100};
    char *nb = malloc(sizeof(char) * 10);

    sfText_setCharacterSize(pic->big, 50);
    while (stick->map[i]) {
        sfText_setPosition(pic->big, big1);
        sfText_setString(pic->big, stick->map[i]);
        sfRenderWindow_drawText(window, pic->big, NULL);
        if (i != 0 && stick->map[i + 1]) {
            tempo = big1.x;
            big1.x = 100;
            sfText_setPosition(pic->perline, big1);
            big1.x = tempo;
            nb = increase_score(nb, nb_stick(stick->map[i]));
            sfText_setString(pic->perline, nb);
            sfRenderWindow_drawText(window, pic->perline, NULL);
        }
        i = i + 1;
        big1.y = big1.y + 60;
    }
    free(nb);
}
