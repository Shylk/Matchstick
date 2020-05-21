/*
** EPITECH PROJECT, 2020
** prototype
** File description:
** proto
*/

void my_putchar(char c);
int my_putstr(char const *str);
long long int my_getnbr(char const *str);
int my_atoi(char *str);
int my_put_nbr(int nb);
void print_map(char **map, int nb_lines);
char **load_into_map(int nb_lines);
int change_turn(int turn);
void remove_stick(char **map, int matches, int line);
void print_who_remove_what(int line, int matches, int turn);
int get_line(int nb_lines);
int line_management(int nb_lines, char **map, int line);
int get_matches(void);
int matches_management(int nb_matches_max, int line, char **map);
int check_if_line_is_null(char **map, int line);
int line_ai(int nb_lines, char **map);
int matches_ai(int nb_matches_max, int line, char **map, int nb_lines);
int error_management(int argc, char **argv);
int end(char **map, int turn, int nb_lines);
int my_strlen(char const *str);
