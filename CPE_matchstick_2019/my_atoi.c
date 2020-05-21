/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_atoi
*/

#include <stdio.h>

int my_atoi(char *str)
{
    int result = 0;
    int max = 0;

    if (str[0] == '-');
    for (; str[max] != '\0'; max++);
    for (int i = 0; i < max - 1; i++) {
        result = (result * 10) + (str[i] - '0');
    }
    return (result);
}
