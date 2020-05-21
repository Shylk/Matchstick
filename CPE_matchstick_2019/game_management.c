/*
** EPITECH PROJECT, 2020
** game
** File description:
** management
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int end(char **map, int turn, int nb_lines)
{
    int count = 0;
    int j = 0;

    for (int i = 0; i <= nb_lines; i++)
        for (j = 1; map[i][j] != '\0'; j++) {
            if (map[i][j] == '|')
                count++;
        }
    if (count == 0 && turn == 1) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    if (count == 0 && turn == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}

int change_turn(int turn)
{
    if (turn == 1) {
        my_putstr("AI's turn...\n");
        turn = 0;
    }
    else if (turn == 0) {
        my_putstr("Your turn:\n");
        turn = 1;
    }
    return (turn);
}

void remove_stick(char **map, int matches, int line)
{
    int one = 0;
    int max = 0;

    for (; map[line][one] != '|' && map[line][one] != '\0'; one++);
    for (; map[line][one] == '|' && map[line][one] != '\0'; one++);
    max = one - matches;
    for (; one >= max; one--) {
        if (map[line][one] != '|');
        else
            map[line][one] = ' ';
    }
}

void print_who_remove_what(int line, int matches, int turn)
{
    if (turn == 1) {
        my_putstr("Player removed ");
        my_put_nbr(matches);
        my_putstr(" match(es) from line ");
        my_put_nbr(line);
    }
    else if (turn == 0) {
        my_putstr("AI removed ");
        my_put_nbr(matches);
        my_putstr(" match(es) from line ");
        my_put_nbr(line);
    }
    my_putstr("\n");
}
