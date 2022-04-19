/*
** EPITECH PROJECT, 2021
** Manage map.
** File description:
** Manage Map function file.
*/

#include "sokoban.h"
#include "lib.h"

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat file_stat;
    char *buffer;
    int len = 0;

    if (fd == -1)
        return (NULL);
    else if (stat(filepath, &file_stat) == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (file_stat.st_size + 1));
    len = read(fd, buffer, file_stat.st_size);
    if (buffer == NULL || len == -1)
        return (NULL);
    buffer[file_stat.st_size] = '\0';
    return (buffer);
}

int verif_map(char *map)
{
    if (verif_char_invalid(map) == 84)
        return (84);
    else if (verif_number_element(map) == 84)
        return (84);
    else
        return (0);
}

int verif_char_invalid(char *map)
{
    char valid_char[] = " \n#XOP";

    for (int i = 0; map[i] != '\0'; i++) {
        if (my_strchr(valid_char, map[i]) == 1)
            return (84);
    }
    return (0);
}

int verif_number_element(char *map)
{
    int player = 0;
    int box = 0;
    int storage = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'P')
            player++;
        else if (map[i] == 'X')
            box++;
        else if (map[i] == 'O')
            storage++;
    }
    if (player != 1 || box <= 0)
        return (84);
    else if (storage <= 0 || box != storage)
        return (84);
    return (0);
}
