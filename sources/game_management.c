/*
** EPITECH PROJECT, 2021
** game_event
** File description:
** game_management
*/

#include "sokoban.h"
#include "lib.h"

void get_input(my_sokoban *game)
{
    int input = getch();

    if (input == 32)
        reset_game(game);
    else {
        key_left_and_right(game, input);
        key_up_and_down(game, input);
    }
}

void get_player_pos(my_sokoban *game)
{
    for (int i = 0; game->map[i] != NULL; i++) {
        for (int k = 0; game->map[i][k] != '\0'; k++) {
            if (game->map[i][k] == 'P') {
                game->player_x = k;
                game->player_y = i;
                return;
            }
        }
    }
}

void close_game(my_sokoban *game, WINDOW *win)
{
    clear();
    endwin();
    delwin(win);
    tab_char_free(game->map);
    tab_char_free(game->init_map);
    free(game);
}

void print_map(my_sokoban *game)
{
    for (int i = 0; game->map[i] != NULL; i++) {
        mvprintw(i, 0, "%s\n", game->map[i]);
    }
}

void replace_storage_location(my_sokoban *game)
{
    for (int i = 0; game->init_map[i] != NULL; i++) {
        for (int j = 0; game->init_map[i][j] != '\0'; j++) {
            if (game->init_map[i][j] == 'O' && game->map[i][j] == ' ')
                game->map[i][j] = 'O';
        }
    }
}
