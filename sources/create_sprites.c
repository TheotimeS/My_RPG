/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** interface.c
*/

#include "../includes/menu.h"

void init_welcome(window *wndw, options *sprt)
{
    sfVector2f prems = {0, 0};
    sfIntRect first = {0, 0, 1920, 1080};
    sprt->spwelcome = sfSprite_create();
    sfSprite_setTexture(sprt->spwelcome, sprt->welcome, sfTrue);
    sfSprite_setPosition(sprt->spwelcome, prems);
}

void init_barre(window *wndw, options *sprt)
{
    sfVector2f prems = {0, 0};
    sfIntRect first = {0, 0, 1920, 1080};
    sprt->spbarre = sfSprite_create();
    sfSprite_setTexture(sprt->spbarre, sprt->barre, sfTrue);
    sfSprite_setPosition(sprt->spbarre, prems);
}

void init_pause(window *wndw, options *sprt)
{
    sfVector2f prems = {0, 0};
    sfIntRect first = {0, 0, 1920, 1080};
    sprt->pause_sprt = sfSprite_create();
    sfSprite_setTexture(sprt->pause_sprt, sprt->pause_txt, sfTrue);
    sfSprite_setPosition(sprt->pause_sprt, prems);
}

void init_tuto(window *wndw, options *sprt)
{
    sfIntRect rect = {469, 627, 468, 312};
    sfVector2f scale = {1920.0 / 468.0, 1080.0 / 312.0};
    sprt->tutorial = sfSprite_create();
    sfSprite_setTexture(sprt->tutorial, sprt->tuto, sfTrue);
    sfSprite_setTextureRect(sprt->tutorial, rect);
    sfSprite_setScale(sprt->tutorial, scale);
}
