/*
** EPITECH PROJECT, 2021
** sokoban_struct.
** File description:
** sokoban_struct
*/

#ifndef SOKOBAN_STRUCT_H_
#define SOKOBAN_STRUCT_H_

typedef struct sokoban {
    char **init_map;
    char **map;
    int status;
    int player_x;
    int player_y;
    int number_of_box;
    int number_of_victory_box;
} my_sokoban;

#endif