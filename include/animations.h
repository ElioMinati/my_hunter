/*
** EPITECH PROJECT, 2021
** animations.h
** File description:
** animation function prototypes
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef ANIMATIONS_H_
#define ANIMATIONS_H_

struct duck_pos {
    float x;
    float y;
};

struct ducks_info {
    struct duck_pos first_duck;
    struct duck_pos second_duck;
    struct duck_pos dead_duck;
    struct duck_pos sec_dead_duck;
    int score;
    int is_first_dead;
    int is_second_dead;
};

sfIntRect move_rect(sfIntRect rect, int offset, int max_value);

sfIntRect rect_clock(sfClock *clock, sfTime time, sfIntRect rect);

struct duck_pos coords_clock(sfClock *clock, sfTime time,
struct duck_pos coords);

int one_second_clock(void);

void create_duck_sprite(sfRenderWindow *window, sfIntRect rect,
struct duck_pos coords);

void display_sky(sfRenderWindow *window);

struct duck_pos modify_duck_coords(struct duck_pos coords, float seconds);

void create_duck_sprite_inv(sfRenderWindow *window, sfIntRect rect,
struct duck_pos coords);

struct duck_pos modify_second_duck_coords(struct duck_pos coords);

struct ducks_info setup_duck_coords(struct ducks_info coords);

struct ducks_info display_dead_duck(sfRenderWindow *window,
struct ducks_info coords, int l);

struct ducks_info display_sec_dead_duck(sfRenderWindow *window,
struct ducks_info coords, int l);

void display_grass(sfRenderWindow *window);

void display_tree(sfRenderWindow *window);

void display_score(sfRenderWindow *window, int score);

struct ducks_info duck_is_dead(struct ducks_info coords);

struct ducks_info second_duck_is_dead(struct ducks_info coords);

void display_gun(sfRenderWindow *window, sfEvent event);

#endif /* !ANIMATIONS_H_ */
