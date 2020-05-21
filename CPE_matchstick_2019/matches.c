/*
** EPITECH PROJECT, 2020
** matches
** File description:
** matches
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int check_if_line_is_null(char **map, int line)
{
    int count = 0;

    for (int j = 0; map[line][j] != '\0'; j++) {
        if (map[line][j] == '|')
            count++;
    }
    return (count);
}

void print_error(int nb_matches_max)
{
    my_putstr("Error: you cannot remove more than ");
    my_put_nbr(nb_matches_max);
    my_putstr(" matches per turn\n");
}

int get_matches(void)
{
    char *matches_str = malloc(sizeof(char) * 3);
    size_t matches_size = 3;
    int matches = 0;

    my_putstr("Matches: ");
    matches_size = getline(&matches_str, &matches_size, stdin);
    if (matches_size == -1)
        return (919);
    for (int i = 0; matches_str[i] != '\0'; i++)
        if (matches_str[i] != 10 && matches_str[i] != 0)
            if (matches_str[i] < '0' || matches_str[i] > '9') {
                return (-2);
            }
    matches = my_atoi(matches_str);
    return (matches);
}

int matches_management(int nb_matches_max, int line, char **map)
{
    int matches = 0, count = check_if_line_is_null(map, line);
    matches = get_matches();
    if (matches == 919)
        return (-2);
    if (matches == -2) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (-1);
    }
    if (matches < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        return (-1);
    }
    if (matches > nb_matches_max) {
        print_error(nb_matches_max);
        return (-1);
    }
    if (count == 0 || matches > count) {
        my_putstr("Error: not enough matches on this line\n");
        return (-1);
    }
    return (matches);
}

int matches_ai(int nb_matches_max, int line, char **map, int nb_lines)
{
    int matches = 0, count = 0, j = 0;

    for (j = 0; map[line][j] != '\0'; j++)
        if (map[line][j] == '|')
            count++;
    matches = count - 1;
    if (matches > nb_matches_max)
        matches = nb_matches_max;
    if (matches <= 0)
        matches = 1;
    return (matches);
}
