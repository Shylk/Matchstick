int line_remaining(char **map, int nb_lines)
{
    int count = 0, j = 1;

    for (int i = 0; i <= nb_lines; i++) {
        for (j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == '|') {
                count++;
                while (map[i][j] != '\0')
                    j++;
            }
        }
    }
    return (count);
}
