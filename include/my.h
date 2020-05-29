/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my header file containing all prototypes
*/

#ifndef __MY_H__
#define __MY_H__

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

int errors(int ac, char **av);

int sticks(char **array);

char **ai(char **array, char *line);

void printer(char **array);

int stick_line(char *array, char *size, int nb);

int player_matches(char **array, char *size, char *size_two, int line);

int stick_matches(char *array, char *size, int nb);

int player_turn(char **array, char *size, char *size_two);

int checker(char **array);

int my_getnb_n(char *str);

void my_putchar(char c);

int my_put_nbr(int nb);

char **editor(char **array, int line, int match, char *size);

int stick_matches_two(char *array, int sz, int nb);

int my_putstr(char const *str);

int my_getnb(char *str);

#endif
