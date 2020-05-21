/*
** EPITECH PROJECT, 2020
** map
** File description:
** management
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char **load_into_map(int nb_lines)
{
    char **map = malloc(sizeof(char *) * nb_lines + 2);
    int j = 0, incre = 0, nb_stick = 1, start = 0;
    int nb_lines_max = nb_lines + 2, nb = 0, new_nb = 0;
    int middle = (nb_lines * 2 + 1) / 2;
    for (int i = 0; i < nb_lines_max; i++)
        map[i] = malloc(sizeof(char) * nb_lines_max * 2 + 3);
    for (int i = 0; j < (nb_lines * 2 + 1); j++)
        map[i][j] = '*';
    for (int i = 1; i < nb_lines_max - 1; i++, middle--, nb_stick += 2) {
        map[i][0] = '*';
        for (start = 1; start < middle; start++)
            map[i][start] = ' ';
        for (nb = start; nb < nb_stick + start; nb++)
            map[i][nb] = '|';
        for (new_nb = nb_stick + start; new_nb < nb_lines * 2; new_nb++)
            map[i][new_nb] = ' ';
        map[i][new_nb] = '*';
    }
    for (int i = 0; i < (nb_lines * 2 + 1); i++)
        map[nb_lines_max - 1][i] = '*';
    return (map);
}

void print_map(char **map, int nb_lines)
{
    for (int i = 0; i < nb_lines + 2; i++) {
        my_putstr(map[i]);
        my_putstr("\n");
    }
}
