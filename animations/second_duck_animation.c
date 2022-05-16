/*
** EPITECH PROJECT, 2021
** second_duck_animation
** File description:
** animation of the second duck
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "animations.h"
#include "my.h"

struct ducks_info display_sec_dead_duck(sfRenderWindow *window,
struct ducks_info coords, int l)
{
    sfIntRect rect;
    sfTexture *texture = sfTexture_createFromFile("images/sps.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f coordinates = {coords.sec_dead_duck.x, coords.sec_dead_duck.y};
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
    if (coords.is_second_dead == 1)
        sfRenderWindow_clear(window, sfBlack);
    if (coords.is_second_dead == 10)
        coords.sec_dead_duck.y += 20;
    return coords;
}

struct duck_pos modify_second_duck_coords(struct duck_pos coords)
{
    if (coords.x < -110) {
        coords.x = 1390;
        coords.y = rand() % 300;
        return coords;
    }
    coords.x = coords.x - 10;
    return coords;
}

void create_duck_sprite_inv(sfRenderWindow *window, sfIntRect rect,
struct duck_pos coords)
{
    sfTexture *texture = sfTexture_createFromFile("images/dsps.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f coordinates = {(coords.x), coords.y};
    sfVector2f scale = {-1, 1};

    rect.top = 0;
    rect.width = 110;
    rect.height = 110;
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, coordinates);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

struct ducks_info second_duck_is_dead(struct ducks_info coords)
{
    coords.sec_dead_duck.x = coords.second_duck.x - 110;
    coords.sec_dead_duck.y = coords.second_duck.y;
    coords.second_duck.x = 1390;
    coords.second_duck.y = rand() % 300;
    coords.score = coords.score + 10;
    coords.is_second_dead = 1;
    return coords;
}
