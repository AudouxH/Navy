/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** map_in_game2.c
*/

#include "../include/navy.h"

int change_map_enemy(char **map_enemy, char *attack)
{
    int y = (attack[0] - 64);
    int i = (attack[1] - 48);

    pause();
    if (navy == 10) {
        write(1, attack, my_strlen(attack));
        write(1, ": missed\n\n", 10);
        map_enemy[i - 1][y - 1] = 'o';
    }
    else {
        write(1, attack, my_strlen(attack));
        write(1, ": hit\n\n", 7);
        map_enemy[i - 1][y - 1] = 'x';
    }
}

int count_hit(char **map)
{
    int hit_map = 0;

    for (int i = 0; i < 8; i++)
        for (int y = 0; y < 8; y++)
            if (map[i][y] == 'x')
                hit_map++;
    return (hit_map);
}

int check_attack(char *attack)
{
    if (((attack[0] - 64) < 1) || ((attack[0] - 64) > 8)) {
        write(1, "wrong position\n", 15);
        return (-1);
    }
    if (((attack[1] - 48) < 1) || ((attack[1] - 48) > 8)) {
        write(1, "wrong position\n", 15);
        return (-1);
    }
    return (0);
}

int check_end(char **map, char **map_enemy)
{
    int y = count_hit(map);
    int z = count_hit(map_enemy);

    if (z == 14)
        return (0);
    else if (y == 14)
        return (1);
    return (2);
}