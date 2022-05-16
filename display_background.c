/*
** EPITECH PROJECT, 2021
** display_background
** File description:
** functions to display all background information
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include "animations.h"
#include "my.h"

void display_sky(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("images/sky.png",
    NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f resize = {3, 2.5};

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_scale(sprite, resize);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void display_grass(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("images/grass.png",
    NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f coordinates = {0, 40};
    sfIntRect rect;
    sfVector2f resize = {1.5, 2.3};

    rect.left = 420;
    rect.top = 0;
    rect.width = 1000;
    rect.height = 317;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, coordinates);
    sfSprite_scale(sprite, resize);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void display_tree(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("images/tree.png",
    NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f coordinates = {110, 175};
    sfIntRect rect;
    sfVector2f resize = {1.2, 1.2};

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, coordinates);
    sfSprite_scale(sprite, resize);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}
