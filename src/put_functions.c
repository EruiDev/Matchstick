/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** My_put_number
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    } else if (nb < 0) {
        nb = nb *-1;
        my_putchar(45);
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + 48);
    return (0);
}

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return (0);
}

int my_getnb(char *str)
{
    int f = 0;
    int nb = 0;

    if (str[0] == '-')
        f++;
    while (str[f] != '\0') {
        if (str[f] < '0' || str[f] > '9')
            return (-1);
        nb += str[f] - 48;
        nb *= 10;
        f++;
    }
    nb /= 10;
    if (str[0] == '-')
        return (-1 * nb);
    else
        return (nb);
}

int my_getnb_n(char *str)
{
    int f = 0;
    int nb = 0;

    if (str[0] == '-')
        return (-2);
    while (str[f] != '\n') {
        if (str[f] < '0' || str[f] > '9')
            return (-2);
        nb += str[f] - 48;
        nb *= 10;
        f++;
    }
    if (f >= 5)
        return (-1);
    nb /= 10;
    if (str[0] == '-')
        return (-1 * nb);
    else
        return (nb);
}