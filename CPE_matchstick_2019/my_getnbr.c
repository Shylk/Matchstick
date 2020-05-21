/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** display a number accord to the string
*/

#include <stdio.h>

long long int my_getnbr(char const *str)
{
    long long int i = 0;
    long long int j = 0;
    int turn_into_minus = 1;
    long long int stock_value = 0;

    if (str[0] == '-') {
        turn_into_minus = -1;
        j = 1;
    }
    for (i; str[i] != '\0'; i++) {
        for (j; str[j] <= '9' && str[j] >= '0' || str[j] != '\0'; j++) {
            stock_value = (stock_value * 10) + (str[j] - '0');
        }
        if (stock_value > 2147483647 || stock_value < -2147483647)
            return (0);
    }
    if (turn_into_minus == -1) {
        stock_value = -stock_value;
    }
    return (stock_value);
}
