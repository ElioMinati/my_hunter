/*
** EPITECH PROJECT, 2021
** window
** File description:
** window with sfrenderwindow
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include "my.h"
#include "animations.h"

struct ducks_info manage_mouse_click(sfMouseButtonEvent event,
struct ducks_info coords)
{
    int x = coords.first_duck.x;
    int y = coords.first_duck.y;

    if (event.x >= x && event.x <= (x + 110)) {
        if (event.y >= y && event.y <= (y + 110)) {
            coords = duck_is_dead(coords);
        }
    }
    x = coords.second_duck.x;
    y = coords.second_duck.y;
    if (event.x >= (x - 110) && event.x <= x) {
        if (event.y >= y && event.y <= (y + 110)) {
            coords = second_duck_is_dead(coords);

        }
    }
    return coords;
}

struct ducks_info analyse_events(sfRenderWindow *window, sfEvent event,
struct ducks_info coords)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
        coords = manage_mouse_click(event.mouseButton, coords);
    }
    return coords;
}

sfRenderWindow *window_create(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1280, 769, 32};

    window = sfRenderWindow_create(video_mode,
    "My window", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 30u);
    return window;
}

struct ducks_info display_all(sfRenderWindow *window, sfIntRect rect,
struct ducks_info coords, sfEvent event)
{
    display_sky(window);
    display_tree(window);
    create_duck_sprite(window, rect, coords.first_duck);
    create_duck_sprite_inv(window, rect, coords.second_duck);
    display_score(window, coords.score);
    if (coords.is_first_dead < 10) {
        coords = display_dead_duck(window, coords, 0);
        ++coords.is_first_dead;
    } else if (coords.is_first_dead == 10) {
        coords = display_dead_duck(window, coords, 40);
    }
    if (coords.is_second_dead < 10) {
        coords = display_sec_dead_duck(window, coords, 0);
        ++coords.is_second_dead;
    } else if (coords.is_second_dead == 10) {
        coords = display_sec_dead_duck(window, coords, 40);
    }
    display_grass(window);
    display_gun(window, event);
    return coords;
}

void exec_game(void)
{
    struct ducks_info coords;
    sfClock *clock;
    sfClock *clock2;
    sfTime time;
    sfIntRect rect;
    sfRenderWindow *window;
    sfEvent event;
    float seconds;

    coords = setup_duck_coords(coords);
    rect.left = 0;
    clock = sfClock_create();
    clock2 = sfClock_create();
    window = window_create();
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        seconds = sfTime_asSeconds(sfClock_getElapsedTime(clock2));
        sfClock_restart(clock2);
        coords.first_duck = modify_duck_coords(coords.first_duck, seconds);
        coords.second_duck = modify_second_duck_coords(coords.second_duck);
        while (sfRenderWindow_pollEvent(window, &event))
            coords = analyse_events(window, event, coords);
        rect = rect_clock(clock, time, rect);
        coords = display_all(window, rect, coords, event);
    }
}
