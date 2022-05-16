/*
** EPITECH PROJECT, 2021
** window.h
** File description:
** window header
*/

#include <SFML/Graphics.h>

#ifndef WINDOW_H_
#define WINDOW_H_

void window_create(void);

struct duck_pos analyse_events(sfRenderWindow *window, sfEvent event,
struct duck_pos coords);

struct duck_pos manage_mouse_click(sfMouseButtonEvent event,
struct duck_pos coords);

#endif /* !WINDOW_H_ */
