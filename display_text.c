/*
** EPITECH PROJECT, 2021
** display_text
** File description:
** functions to display text on screen
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "animations.h"
#include "my.h"

void display_score(sfRenderWindow *window, int score)
{
    char *score_str = malloc(14 * sizeof(char));
    sfFont *font = sfFont_createFromFile("images/pixeled.ttf");
    sfText *text = sfText_create();
    sfVector2f pos_text = {10, 10};

    if (score == 0) {
        sfText_setString(text, "0");
    } else {
        score_str = int_to_str(score);
        sfText_setString(text, score_str);
    }
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, pos_text);
    sfRenderWindow_drawText(window, text, NULL);
}
