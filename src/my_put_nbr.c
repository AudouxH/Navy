/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** my_put_nbr.c
*/

#include "../include/navy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int find_digit(int x)
{
    int i = 0;

    while (x > 0) {
        x = x / 10;
        i++;
    }
    return (i);
}

void disp_val(int v)
{
    int x = 0;
    if (v <= 9) {
        my_putchar(48 + v);
    } else {
        x = v / 10;
        x *= 10;
        my_putchar(48 + (v - x));
    }
}

void my_put_nbr(int nb)
{
    int target_pow = 0;
    int actual_digit = 0;
    int value = 0;

    if (nb != 0) {
        if (nb < 0) {
            my_putchar('-');
            nb = nb * -1;
        }
        target_pow = find_digit(nb);
        while (target_pow > 0) {
            value = nb;
            for (int i = 1; i < target_pow; i++) {
                value = value / 10;
            }
            disp_val(value);
            --target_pow;
        }
    } else
        my_putchar('0');
}

int my_getnbr(char const *str)
{
    int nb = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            while (str[i] >= '0' && str[i] <= '9') {
                nb = (nb * 10) + str[i] - '0';
                i++;
            }
            if (str[0] == 45)
                return (nb * -1);
            return (nb);
        }
    }
}
