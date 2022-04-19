/*
** EPITECH PROJECT, 2021
** B-PSU-200-BDX-2-1-mysokoban-hugo.lumet
** File description:
** box mouvement
*/

#include "sokoban.h"
#include "lib.h"

int move_left(my_sokoban *game)
{
    if (game->map[game->player_y][game->player_x - 2] == '#')
        return (1);
    else if (game->map[game->player_y][game->player_x - 2] == 'X')
        return (1);
    else {
        game->map[game->player_y][game->player_x - 1] = ' ';
        game->map[game->player_y][game->player_x - 2] = 'X';
        return (0);
    }
}

int move_right(my_sokoban *game)
{
    if (game->map[game->player_y][game->player_x + 2] == '#')
        return (1);
    else if (game->map[game->player_y][game->player_x + 2] == 'X')
        return (1);
    else {
        game->map[game->player_y][game->player_x + 1] = ' ';
        game->map[game->player_y][game->player_x + 2] = 'X';
        return (0);
    }
}

int move_up(my_sokoban *game)
{
    if (game->map[game->player_y - 2][game->player_x] == '#')
        return (1);
    else if (game->map[game->player_y - 2][game->player_x] == 'X')
        return (1);
    else {
        game->map[game->player_y - 1][game->player_x] = ' ';
        game->map[game->player_y - 2][game->player_x] = 'X';
        return (0);
    }
}

int move_down(my_sokoban *game)
{
    if (game->map[game->player_y + 2][game->player_x] == '#')
        return (1);
    else if (game->map[game->player_y + 2][game->player_x] == 'X')
        return (1);
    else {
        game->map[game->player_y + 1][game->player_x] = ' ';
        game->map[game->player_y + 2][game->player_x] = 'X';
        return (0);
    }
}
