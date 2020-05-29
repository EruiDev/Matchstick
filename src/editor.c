/*
** EPITECH PROJECT, 2020
** editor.
** File description:
** This is actually the editor of the array
*/

#include "../include/my.h"

char **editor(char **array, int line, int match, char *size)
{
    int c = 0;
    char *buffer = array[line];
    int sz = my_getnb(size);

    my_putstr("Player removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');

    for (int y = sz * 2 - 1; buffer[y] != '\0'; y--) {
        if (buffer[y] == '|') {
            if (match != c) {
                array[line][y] = ' ';
                c++;
            }
        }
    }
    printer(array);
    return (array);
}

int stick_matches_two(char *array, int sz, int nb)
{
    if (nb > sz || nb == -1) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(sz);
        my_putstr(" matches per turn");
        return (0);
    } else if (nb <= 0) {
        my_putstr("Error: you have to remove at least one match");
        return (0);
    }
}