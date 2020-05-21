/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int error_management(int argc, char **argv)
{
    if (argc != 3)
        return (84);
    for (int j = 0; argv[1][j] != '\0'; j++)
        if (argv[1][j] < '0' || argv[1][j] > '9')
            return (84);
    for (int j = 0; argv[2][j] != '\0'; j++)
        if (argv[2][j] < '0' || argv[2][j] > '9')
            return (84);
    if (my_getnbr(argv[1]) <= 1 || my_getnbr(argv[1]) >= 100)
        return (84);
    return (0);
}
