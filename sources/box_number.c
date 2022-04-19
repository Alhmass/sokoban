/*
** EPITECH PROJECT, 2021
** box_number
** File description:
** box_number
*/

#include "sokoban.h"
#include "lib.h"

void get_box_number(my_sokoban *game)
{
    for (int i = 0; game->map[i] != NULL; i++) {
        for (int k = 0; game->map[i][k] != '\0'; k++)
            if (game->map[i][k] == 'X')
                game->number_of_box += 1;
    }
}
