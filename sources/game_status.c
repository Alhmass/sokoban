/*
** EPITECH PROJECT, 2021
** game_status
** File description:
** game_status
*/

#include "sokoban.h"
#include "lib.h"

void game_status(my_sokoban *game)
{
    verif_game_over(game);
    verif_victory(game);
}

void verif_victory(my_sokoban *game)
{
    for (int i = 0; game->map[i] != NULL; i++) {
        for (int k = 0; game->map[i][k] != '\0'; k++) {
            if (game->map[i][k] == 'X' && game->init_map[i][k] == 'O')
                game->number_of_victory_box += 1;
        }
    }
    if (game->number_of_victory_box == game->number_of_box)
        game->status = 0;
    else
        game->number_of_victory_box = 0;
}

void verif_game_over(my_sokoban *game)
{
    for (int i = 0; game->map[i] != NULL; i++) {
        for (int k = 0; game->map[i][k] != '\0'; k++) {
            if (game->map[i][k] == 'X' && game->init_map[i][k] != 'O')
                verif_blocked_box(game, i, k);
        }
    }
}

void verif_blocked_box(my_sokoban *game, int i, int k)
{
    int blocked = 0;

    if (game->map[i + 1][k] == '#' || game->map[i - 1][k] == '#')
        blocked += 1;
    if (game->map[i][k - 1] == '#' || game->map[i][k + 1] == '#')
        blocked += 1;
    if (blocked == 2)
        game->status = 1;
}
