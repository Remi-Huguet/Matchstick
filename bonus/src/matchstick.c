/*
** EPITECH PROJECT, 2021
** e
** File description:
** e
*/
#include "../include/lib_csfml.h"
#include "../include/matchstick.h"
#include <stdlib.h>

sfRenderWindow *get_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};

    window = sfRenderWindow_create(mode, "matchstick", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}

void init_stick(stick_t *stick)
{
    stick->coup = 1;
    stick->lines = 2;
    stick->game2 = 0;
    stick->turn = 0;
    stick->line = 1;
    stick->matches = 1;
    stick->win = 0;
}

int matchstick(void)
{
    sfRenderWindow *window = get_window();
    sfEvent event;
    pic_t *pic = malloc(sizeof(pic_t));
    stick_t *stick = malloc(sizeof(stick_t));
    sfVector2i aim;

    init_stick(stick);
    init_pictures(pic);
    while (sfRenderWindow_isOpen(window) && event.key.code != sfKeyEscape && stick->win >= 0) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        aim = sfMouse_getPositionRenderWindow(window);
        sfRenderWindow_clear(window, sfBlack);
        if (stick->game2 == 0)
            menu(window, pic, stick, aim);
        if (stick->game2 >0)
            game(window, stick, pic, aim);
        sfRenderWindow_display(window);
    }
    free(stick);
    free(pic);
    if (stick->win == -1)
        return (1);
    return (2);
}

int main(int ac, char **av)
{
    return (matchstick());
}
