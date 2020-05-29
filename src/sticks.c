/*
** EPITECH PROJECT, 2020
** sticks.c
** File description:
** some functionalities of that are needed to make the matchstick work
*/

#include "../include/my.h"

int sticks(char **array)
{
    int y = 0;
    int x = 0;
    int c = 0;

    for (y = 0; array[y] != NULL; y++) {
        for (x = 0; array[y][x] != '\0'; x++) {
            if (array[y][x] == '|') {
                c++;
            }
        }
    }
    return (c);
}

int stick_line(char *array, char *size, int nb)
{
    int c = 0;
    int y = 0;
    int sz = my_getnb(size);

    if (nb == -2) {
        my_putstr("Error: invalid input (positive number expected)");
        return (0);
    }
    if (nb <= 0 || nb > sz) {
        my_putstr("Error: this line is out of range");
        return (0);
    }
    return (1);
}

int player_matches(char **array, char *size, char *size_two, int line)
{
    size_t bytes;
    char *number;
    int nb = 0;

    my_putstr("Matches: ");
    bytes = 0;
    number = NULL;
    if (getline(&number, &bytes, stdin) < 0)
        return (-1);
    nb = my_getnb_n(number);
    if (stick_matches(array[line], size_two, nb) != 0) {
        editor(array, line, nb, size);
    } else {
        player_turn(array, size, size_two);
    }
    return (0);
}

int player_turn(char **array, char *size, char *size_two)
{
    size_t bytes;
    char *number;
    int nb = 0;

    my_putstr("\nLine: ");
    bytes = 0;
    number = NULL;
    if (getline(&number, &bytes, stdin) < 0)
        return (-1);
    nb = my_getnb_n(number);
    if (stick_line(array[nb], size, nb) != 0) {
        if (player_matches(array, size, size_two, nb) == -1)
            return (-1);
    } else {
        player_turn(array, size, size_two);
    }
    return (0);
}

int stick_matches(char *array, char *size, int nb)
{
    int sz = my_getnb(size);
    int c = 0;

    for (int y = 0; array[y] != '\0'; y++) {
        if (array[y] == '|') {
            c++;
        }
    }
    if (nb == -2) {
        my_putstr("Error: invalid input (positive number expected)");
        return (0);
    }
    if (stick_matches_two(array, sz, nb) == 0)
        return (0);
    if (c < nb) {
        my_putstr("Error: not enough matches on this line");
        return (0);
    }
    return (c);
}
