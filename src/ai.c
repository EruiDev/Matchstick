/*
** EPITECH PROJECT, 2020
** ai.c
** File description:
** This file is going to cointain the ai
*/

#include "../include/my.h"

int get_match(char **array, int line)
{
    int random = rand() % line + 1;
    char *checker = array[random];

    for (int y = line * 2 - 1; checker[y] != '\0'; y--) {
        if (checker[y] == '|') {
            array[random][y] = ' ';
            my_put_nbr(random);
            return (random);
        }
        if (checker[y] == '*') {
            get_match(array, line);
        }
    }
    return (0);
}

char **ai(char **array, char *line)
{
    int lines = my_getnb(line);
    int nb = 0;

    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed 1 match(es) from line ");
    nb = get_match(array, lines);
    my_putchar('\n');
    printer(array);
    return (array);
}

int checker(char **array)
{
    for (int y = 0; array[y] != NULL; y++) {
        for (int x = 0; array[y][x] != '\0'; x++) {
            if (array[y][x] == '|') {
                return (1);
            }
        }
    }
    return (0);
}
