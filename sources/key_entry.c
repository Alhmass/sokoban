/*
** EPITECH PROJECT, 2021
** key_move
** File description:
** key_entry
*/

#include "sokoban.h"
#include "lib.h"

void key_up_and_down(my_sokoban *game, int input)
{
    if (input == KEY_UP)
        arrow_up(game);
    else if (input == KEY_DOWN)
        arrow_down(game);
}

void key_left_and_right(my_sokoban *game, int input)
{
    if (input == KEY_RIGHT)
        arrow_right(game);
    else if (input == KEY_LEFT)
        arrow_left(game);
}
