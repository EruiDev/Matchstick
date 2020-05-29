/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** This is the matchstick program
*/

#include "../include/my.h"

char **general_generator(char **array, char **av, int o)
{
    int size = my_getnb(av[1]);
    int s = 0;
    int t = 1;
    static int progresion = 0;

    for (s = size - 2; 0 <= s - progresion; s--, t++) {
        array[o][t] = ' ';
    }
    for (s = 0 - progresion; size - size >= s - progresion; s++, t++) {
        array[o][t] = '|';
    }
    for (s = size - 2; 0 <= s - progresion; s--, t++) {
        array[o][t] = ' ';
    }
    progresion++;
    return (array);
}

char **generator_sides(int ac, char **av)
{
    int size = my_getnb(av[1]);
    int f = 0;
    int s = 0;
    char **array = malloc(sizeof(char *) * ((size * 2) + 1));

    array[s] = malloc(sizeof(char) * ((size * 2) + 1));
    for (f = 0; size * 2 >= f; f++)
        array[s][f] = '*';
    for (f = 1; size >= f; f++) {
        s++;
        array[s] = malloc(sizeof(char) * ((size * 2) + 1));
        array[s][0] = '*';
        array = general_generator(array, av, s);
        array[s][size * 2] = '*';
    }
    s++;
    array[s] = malloc(sizeof(char) * ((size * 2) + 1));
    for (f = 0; size * 2 >= f; f++)
        array[s][f] = '*';
    return (array);
}

void printer(char **array)
{
    int f = 0;

    for (f = 0; array[f] != NULL; f++) {
        my_putstr(array[f]);
        my_putchar('\n');
    }
}

int full_game(int ac, char **av)
{
    char **array = generator_sides(ac, av);
    int f = 0;
    int size = my_getnb(av[1]);

    printer(array);
    while (sticks(array) != 0) {
        my_putstr("\nYour turn:");
        if (player_turn(array, av[1], av[2]) == -1)
            return (0);
        if (checker(array) == 0) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        ai(array, av[1]);
        if (checker(array) == 0) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    int end = 0;

    if (errors(ac, av) == 1)
        return (84);
    return (full_game(ac, av));
}