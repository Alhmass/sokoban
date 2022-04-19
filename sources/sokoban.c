/*
** EPITECH PROJECT, 2021
** Sokoban Game function.
** File description:
** sokoban
*/

#include "sokoban.h"
#include "lib.h"

int sokoban(char *filepath)
{
    char *map = read_file(filepath);
    int return_value = 0;

    if (map == NULL)
        return (84);
    else if (verif_map(map) == 84)
        return (84);
    return_value = game_loop(map);
    free(map);
    return (return_value);
}

my_sokoban *init_sokoban_struct(char *map)
{
    my_sokoban *game = malloc(sizeof(my_sokoban));

    if (game == NULL)
        exit(84);
    game->map = str_to_word_tab(map, "\n");
    game->init_map = str_to_word_tab(map, "\n");
    if (game->map == NULL || game->init_map == NULL)
        exit(84);
    game->status = 3;
    get_box_number(game);
    get_player_pos(game);
    return (game);
}

int game_loop(char *map)
{
    my_sokoban *game = init_sokoban_struct(map);
    WINDOW *win = initscr();
    int return_value = 0;

    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    clear();
    while (game->status == 3) {
        print_map(game);
        move(game->player_y, game->player_x);
        refresh();
        get_input(game);
        game_status(game);
        replace_storage_location(game);
    }
    return_value = game->status;
    close_game(game, win);
    return (return_value);
}

void reset_game(my_sokoban *game)
{
    game->number_of_victory_box = 0;
    tab_char_free(game->map);
    game->map = malloc(sizeof(char *) * (my_strstr_len(game->init_map) + 1));
    for (int i = 0; game->init_map[i] != NULL; i++) {
        game->map[i] = malloc(sizeof(char) *
                (my_strlen(game->init_map[i]) + 1));
        game->map[i] = my_strcpy(game->map[i], game->init_map[i]);
    }
    get_player_pos(game);
}
