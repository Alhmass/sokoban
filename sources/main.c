/*
** EPITECH PROJECT, 2021
** My_Sokoban.
** File description:
** My_Sokoban is a console game.
*/

#include "sokoban.h"
#include  "lib.h"

int main(int ac, char **argv)
{
    if (ac < 2)
        return (84);
    else
        return (menu(argv[1]));
}

int menu(char *arg)
{
    if (str_compare("-h", arg) == 1) {
        helping_program();
        return (0);
    }
    else
        return (sokoban(arg));
}