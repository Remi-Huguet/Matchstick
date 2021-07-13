/*
** EPITECH PROJECT, 2021
** init
** File description:
** init
*/
#include "../include/lib_csfml.h"
#include "../include/matchstick.h"

void set_pic_text(pic_t *pic)
{
    sfVector2f t1 = {1400, 490};
    sfVector2f t2 = {1580, 490};
    sfVector2f t3 = {1380, 790};
    sfVector2f t4 = {1580, 790};
    sfVector2f big1 = {225, 120};
    sfVector2f r1 = {80, 80};
    sfVector2f ai = {1500, 400};
    sfVector2f p1 = {1200, 70};
    sfVector2f p2 = {1400, 70};
    sfVector2f p3 = {1480, 70};
    sfVector2f p4 = {1775, 70};

    sfText_setPosition(pic->big, big1);
    sfText_setPosition(pic->txt_lines, t1);
    sfText_setPosition(pic->lines1, t2);
    sfText_setPosition(pic->txt_coup, t3);
    sfText_setPosition(pic->coup1, t4);
    sfText_setPosition(pic->remain, r1);
    sfText_setPosition(pic->ai_turn, ai);
    sfText_setPosition(pic->part1, p1);
    sfText_setPosition(pic->part2, p2);
    sfText_setPosition(pic->part3, p3);
    sfText_setPosition(pic->part4, p4);
    sfText_setString(pic->txt_lines, "Lines :");
    sfText_setString(pic->lines1, "2");
    sfText_setString(pic->txt_coup, "Moves :");
    sfText_setString(pic->coup1, "1");
    sfText_setString(pic->big, "Matchstick");
    sfText_setString(pic->remain, "Stick remaining per line :");
    sfText_setString(pic->perline, NULL);
    sfText_setString(pic->ai_turn, ".");
    sfText_setString(pic->part1, NULL);
    sfText_setString(pic->part2, NULL);
    sfText_setString(pic->part3, NULL);
    sfText_setString(pic->part4, NULL);
}

void set_pic_txt(pic_t *pic)
{
    pic->button = sfTexture_createFrom\
File("pictures/button.png", NULL);
    pic->plus = sfTexture_createFrom\
File("pictures/plus.png", NULL);
    pic->moins = sfTexture_createFrom\
File("pictures/moins.png", NULL);
    pic->txt = sfFont_createFromFile("police/arial.ttf");
    pic->txt_lines = sfText_create();
    pic->txt_coup = sfText_create();
    pic->my_turn = sfText_create();
    pic->lines1 = sfText_create();
    pic->coup1 = sfText_create();
    pic->big = sfText_create();
    pic->remain = sfText_create();
    pic->perline = sfText_create();
    pic->ai_turn = sfText_create();
    pic->part1 = sfText_create();
    pic->part2 = sfText_create();
    pic->part3 = sfText_create();
    pic->part4 = sfText_create();
    sfText_setFont(pic->my_turn, pic->txt);
    sfText_setFont(pic->txt_lines, pic->txt);
    sfText_setFont(pic->txt_coup, pic->txt);
    sfText_setFont(pic->lines1, pic->txt);
    sfText_setFont(pic->coup1, pic->txt);
    sfText_setFont(pic->big, pic->txt);
    sfText_setFont(pic->remain, pic->txt);
    sfText_setFont(pic->perline, pic->txt);
    sfText_setFont(pic->ai_turn, pic->txt);
    sfText_setFont(pic->part1, pic->txt);
    sfText_setFont(pic->part2, pic->txt);
    sfText_setFont(pic->part3, pic->txt);
    sfText_setFont(pic->part4, pic->txt);
    sfText_setCharacterSize(pic->my_turn, 80);
    sfText_setCharacterSize(pic->txt_lines, 50);
    sfText_setCharacterSize(pic->txt_coup, 50);
    sfText_setCharacterSize(pic->lines1, 50);
    sfText_setCharacterSize(pic->coup1, 50);
    sfText_setCharacterSize(pic->big, 170);
    sfText_setCharacterSize(pic->remain, 50);
    sfText_setCharacterSize(pic->perline, 50);
    sfText_setCharacterSize(pic->ai_turn, 200);
    sfText_setCharacterSize(pic->part1, 35);
    sfText_setCharacterSize(pic->part2, 35);
    sfText_setCharacterSize(pic->part3, 35);
    sfText_setCharacterSize(pic->part4, 35);
}

void set_pic_sprite(pic_t *pic)
{
    pic->button1 = sfSprite_create();
    pic->button2 = sfSprite_create();
    pic->button3 = sfSprite_create();
    pic->button4 = sfSprite_create();
    pic->plus1 = sfSprite_create();
    pic->plus2 = sfSprite_create();
    pic->moins1 = sfSprite_create();
    pic->moins2 = sfSprite_create();
    sfSprite_setTexture(pic->button1, pic->button, sfTrue);
    sfSprite_setTexture(pic->button2, pic->button, sfTrue);
    sfSprite_setTexture(pic->button3, pic->button, sfTrue);
    sfSprite_setTexture(pic->button4, pic->button, sfTrue);
    sfSprite_setTexture(pic->plus1, pic->plus, sfTrue);
    sfSprite_setTexture(pic->plus2, pic->plus, sfTrue);
    sfSprite_setTexture(pic->moins1, pic->moins, sfTrue);
    sfSprite_setTexture(pic->moins2, pic->moins, sfTrue);
}

void set_pic_place(pic_t *pic)
{
    sfVector2f b2 = {1700, 500};
    sfVector2f b1 = {1800, 500};
    sfVector2f b4 = {1700, 800};
    sfVector2f b3 = {1800, 800};

    sfSprite_setPosition(pic->button1, b1);
    sfSprite_setPosition(pic->button2, b2);
    sfSprite_setPosition(pic->button3, b3);
    sfSprite_setPosition(pic->button4, b4);
    sfSprite_setPosition(pic->plus1, b1);
    sfSprite_setPosition(pic->plus2, b3);
    sfSprite_setPosition(pic->moins1, b2);
    sfSprite_setPosition(pic->moins2, b4);
}

void set_pic_menu(pic_t *pic)
{
    sfVector2f p1 = {1530, 150};
    sfVector2f f1 = {-300, 0};

    pic->fond = sfTexture_createFrom\
File("pictures/fond.jpg", NULL);
    pic->play = sfTexture_createFrom\
File("pictures/play.png", NULL);
    pic->fond1 = sfSprite_create();
    pic->play1 = sfSprite_create();
    sfSprite_setTexture(pic->fond1, pic->fond, sfTrue);
    sfSprite_setTexture(pic->play1, pic->play, sfTrue);
    sfSprite_setPosition(pic->play1, p1);
    sfSprite_setPosition(pic->fond1, f1);
}

void init_pictures(pic_t *pic)
{
    set_pic_menu(pic);
    set_pic_txt(pic);
    set_pic_sprite(pic);
    set_pic_place(pic);
    set_pic_text(pic);
}
