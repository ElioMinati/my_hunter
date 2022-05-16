/*
** EPITECH PROJECT, 2021
** display_gun
** File description:
** display gun on my_hunter game
*/

#include <SFML/Graphics.h>

void display_gun(sfRenderWindow *window, sfEvent event)
{
    sfTexture *texture = sfTexture_createFromFile("images/gun.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture_s = sfTexture_createFromFile("images/scope.png", NULL);
    sfSprite *sprite_s = sfSprite_create();
    sfVector2i coords = sfMouse_getPositionRenderWindow(window);
    sfVector2f coordinates = {coords.x - 225, 400};
    sfVector2f coordinates_s = {coords.x - 28, coords.y - 28};
    sfVector2f resize = {0.1, 0.1};

    sfSprite_setPosition(sprite, coordinates);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite_s, coordinates_s);
    sfSprite_setTexture(sprite_s, texture_s, sfFalse);
    sfSprite_scale(sprite_s, resize);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite_s, NULL);
}
