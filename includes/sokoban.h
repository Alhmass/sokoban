/*
** EPITECH PROJECT, 2021
** Sokoban headers.
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <curses.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <ncurses.h>
#include "sokoban_struct.h"

char *read_file(char *filepath);
int verif_map(char *map);
int sokoban(char *filepath);
void helping_program(void);
int menu(char *arg);
int game_loop(char *map);
my_sokoban *init_sokoban_struct(char *map);
void get_player_pos(my_sokoban *game);
void arrow_right(my_sokoban *game);
void get_input(my_sokoban *game);
void arrow_left(my_sokoban *game);
void arrow_up(my_sokoban *game);
void arrow_down(my_sokoban *game);
int move_left(my_sokoban *game);
int move_right(my_sokoban *game);
int move_up(my_sokoban *game);
int move_down(my_sokoban *game);
void get_box_number(my_sokoban *game);
void game_status(my_sokoban *game);
void verif_victory(my_sokoban *game);
void verif_game_over(my_sokoban *game);
void verif_blocked_box(my_sokoban *game, int i, int k);
void print_map(my_sokoban *game);
void close_game(my_sokoban *game, WINDOW *win);
void replace_storage_location(my_sokoban *game);
void reset_game(my_sokoban *game);
int verif_number_element(char *map);
int verif_char_invalid(char *map);
void key_up_and_down(my_sokoban *game, int input);
void key_left_and_right(my_sokoban *game, int input);

#endif