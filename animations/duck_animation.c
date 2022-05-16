/*
** EPITECH PROJECT, 2021
** duck_animations
** File description:
** animation functions for the duck
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "animations.h"
#include "my.h"

struct ducks_info display_dead_duck(sfRenderWindow *window,
struct ducks_info coords, int l)
{
    sfIntRect rect;
    sfTexture *texture = sfTexture_createFromFile("images/sps.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f coordinates = {coords.dead_duck.x, coords.dead_duck.y};
    sfVector2f scale = {3.5, 3.5};

    rect.left = l;
    rect.top = 230;
    rect.width = 40;
    rect.height = 37;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, coordinates);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    if (coords.is_first_dead == 1 || coords.is_first_dead == 2)
        sfRenderWindow_clear(window, sfBlack);
    if (coords.is_first_dead == 10)
        coords.dead_duck.y += 20;
    return coords;
}

void create_duck_sprite(sfRenderWindow *window, sfIntRect rect,
struct duck_pos coords)
{
    sfTexture *texture = sfTexture_createFromFile("images/dsps.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f coordinates = {coords.x, coords.y};

    rect.top = 0;
    rect.width = 110;
    rect.height = 110;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, coordinates);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

struct ducks_info setup_duck_coords(struct ducks_info coords)
{
    coords.first_duck.x = -110;
    coords.first_duck.y = 0;
    coords.second_duck.x = 1390;
    coords.second_duck.y = 0;
    coords.score = 0;
    return coords;
}

struct duck_pos modify_duck_coords(struct duck_pos coords, float seconds)
{
    if (coords.x > 1500) {
        coords.x = -110;
        coords.y = rand() % 300;
        return coords;
    }
    coords.x = coords.x + 400 * seconds;
    return coords;
}

struct ducks_info duck_is_dead(struct ducks_info coords)
{
    coords.dead_duck.x = coords.first_duck.x;
    coords.dead_duck.y = coords.first_duck.y;
    coords.first_duck.x = -110;
    coords.first_duck.y = rand() % 300;
    coords.score = coords.score + 10;
    coords.is_first_dead = 1;
    return coords;
}
