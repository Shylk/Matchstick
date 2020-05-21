/*
** EPITECH PROJECT, 2020
** line
** File description:
** line
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int get_line(int nb_lines)
{
    char *line_str = malloc(sizeof(char) * 3);
    size_t line_size = 3;
    int line = 0;

    my_putstr("Line: ");
    line_size = getline(&line_str, &line_size, stdin);
    if (line_size == -1)
        return (-1);
    for (int i = 0; line_str[i] != '\0'; i++)
        if (line_str[i] != 10 && line_str[i] != 0)
            if (line_str[i] < '0' || line_str[i] > '9') {
                return (-2);
            }
    line = my_atoi(line_str);
    return (line);
}

int line_management(int nb_lines, char **map, int line)
{
    int count = 0;

    if (line == -1)
        return (-1);
    line = get_line(nb_lines);
    if (line == -1)
        return (-1);
    if (line == -2) {
        my_putstr("Error: invalid input (positive number expected)\n");
        line = line_management(nb_lines, map, line);
    }
    if (line > nb_lines || line < 1) {
        my_putstr("Error: this line is out of range\n");
        line = line_management(nb_lines, map, line);
    }
    return (line);
}

int line_ai(int nb_lines, char **map)
{
    int line = 0;
    int count = 0;
    int max = 0;
    int line_max = 0;
    int j = 0;

    for (int i = 0; i <= nb_lines; i++) {
        count = 0;
        for (j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == '|' && map[i][j] != ' ')
                count++;
        }
        if (count >= max) {
            line_max = i;
            max = count;
        }
    }
    line = line_max;
    return (line);
}
