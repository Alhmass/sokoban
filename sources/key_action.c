/*
** EPITECH PROJECT, 2021
** key_action
** File description:
** key_action
*/

#include "sokoban.h"
#include "lib.h"

void arrow_right(my_sokoban *game)
{
    int status = 0;

    if (game->map[game->player_y][game->player_x + 1] == '#')
        return;
    else if (game->map[game->player_y][game->player_x + 1] == 'X')
        status = move_right(game);
    if (status != 0)
        return;
    game->map[game->player_y][game->player_x] = ' ';
    game->player_x += 1;
    game->map[game->player_y][game->player_x] = 'P';
}

void arrow_left(my_sokoban *game)
{
    int status = 0;

    if (game->map[game->player_y][game->player_x - 1] == '#')
        return;
    else if (game->map[game->player_y][game->player_x - 1] == 'X')
        status = move_left(game);
    if (status != 0)
        return;
    game->map[game->player_y][game->player_x] = ' ';
    game->player_x -= 1;
    game->map[game->player_y][game->player_x] = 'P';
}

void arrow_up(my_sokoban *game)
{
    int status = 0;

    if (game->map[game->player_y - 1][game->player_x] == '#')
        return;
    else if (game->map[game->player_y - 1][game->player_x] == 'X')
        status = move_up(game);
    if (status != 0)
        return;
    game->map[game->player_y][game->player_x] = ' ';
    game->player_y -= 1;
    game->map[game->player_y][game->player_x] = 'P';
}

void arrow_down(my_sokoban *game)
{
    int status = 0;

    if (game->map[game->player_y + 1][game->player_x] == '#')
        return;
    else if (game->map[game->player_y + 1][game->player_x] == 'X')
        status = move_down(game);
    if (status != 0)
        return;
    game->map[game->player_y][game->player_x] = ' ';
    game->player_y += 1;
    game->map[game->player_y][game->player_x] = 'P';
}
