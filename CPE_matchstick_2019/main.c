/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int player_turn(char **map, int nb_lines, int nb_matches_max, int turn)
{
    int line = 0;
    int matches = 0;

    line = line_management(nb_lines, map, line);
    if (line == -1)
        return (-1);
    matches = matches_management(nb_matches_max, line, map);
    if (matches == -2)
        return (-1);
    while (matches == -1) {
        line = line_management(nb_lines, map, line);
        if (line == -1)
            return (-1);
        matches = matches_management(nb_matches_max, line, map);
        if (matches == -2)
            return (-1);
    }
    remove_stick(map, matches, line);
    print_who_remove_what(line, matches, turn);
    print_map(map, nb_lines);
}

void ai_turn(char **map, int nb_lines, int nb_matches_max, int turn)
{
    int line = 0;
    int matches = 0;

    line = line_ai(nb_lines, map);
    matches = matches_ai(nb_matches_max, line, map, nb_lines);
    remove_stick(map, matches, line);
    print_who_remove_what(line, matches, turn);
    print_map(map, nb_lines);
}

int game_loop(int nb_lines, char **map, int nb_matches_max)
{
    int line = 0;
    int matches = 0;
    int turn = 0;
    int retu = 0;
    int eof = 0;

    while (1) {
        turn = change_turn(turn);
        if (turn == 1)
            eof = player_turn(map, nb_lines, nb_matches_max, turn);
        else if (turn == 0)
            ai_turn(map, nb_lines, nb_matches_max, turn);
        if (eof == -1)
            return (0);
        retu = end(map, turn, nb_lines);
        if (retu != 0)
            return (retu);
        my_putstr("\n");
    }
    return (0);
}

int main_if_no_error(int argc, char **argv)
{
    int nb_lines = my_getnbr(argv[1]);
    char **map = load_into_map(nb_lines);
    int nb_matches_max = my_getnbr(argv[2]);

    print_map(map, nb_lines);
    my_putstr("\n");
    return (game_loop(nb_lines, map, nb_matches_max));
}

int main(int argc, char **argv)
{
    int error = error_management(argc, argv);

    if (error == 84)
        return (84);
    else
        return (main_if_no_error(argc, argv));
}
