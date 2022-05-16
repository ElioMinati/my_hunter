/*
** EPITECH PROJECT, 2021
** clock
** File description:
** 1 second clock
*/

#include "animations.h"
#include "my.h"
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

sfIntRect move_rect(sfIntRect rect, int offset, int max_value)
{
    int current_value = rect.left;

    rect.left = current_value + offset;
    if (rect.left == max_value) {
        rect.left = 0;
    }
    return rect;
}

sfIntRect rect_clock(sfClock *clock, sfTime time, sfIntRect rect)
{
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.15) {
        sfClock_restart(clock);
        rect = move_rect(rect, 110, 330);
        return rect;
    }
    return rect;
}
