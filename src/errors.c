/*
** EPITECH PROJECT, 2020
** errors.c
** File description:
** This is the errors file
*/

#include "../include/my.h"

int errors(int ac, char **av)
{
    int size;
    int match;

    if (ac == 3) {
        size = my_getnb(av[1]);
        match = my_getnb(av[2]);
        if (size > 0 && size <= 100 && match >= 0)
            return (0);
    }
    return (1);
}
