/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** display one by one the characters of a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
