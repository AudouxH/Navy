/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** game_in_play.c
*/

#include "../include/navy.h"

int send_signal(char **map_enemy)
{
    char *attack;

    do {
    write(1, "attack: ", 8);
    attack = get_next_line(0);
    } while (check_attack(attack) == -1);
    for (int cols = (attack[0] - 64); cols > 0; cols--) {
        kill(navy, SIGUSR1);
        usleep(2000);
    }
    kill(navy, SIGUSR2);
    usleep(2000);
    for (int line = (attack[1] - 48); line > 0; line--) {
        kill(navy, SIGUSR1);
        usleep(2000);
    }
    kill(navy, SIGUSR2);
    change_map_enemy(map_enemy, attack);
}

char *receive_signal(char **map, char **map_enemy)
{
    int i = 0;
    int y = 0;
    int z = 0;

    write(1, "waiting for enemy's attack...\n", 30);
    pause();
    while (navy == 10) {
        i++;
        pause();
    }
    pause();
    while (navy == 10) {
        y++;
        pause();
    }
    change_map_after_signal(map, y, i, z);
}

void change_map_after_signal(char **map, int y, int i, int z)
{
    char line = y;
    char cols = i;

    if (map[y - 1][i - 1] == '.') {
        map[y - 1][i - 1] = 'o';
        my_putchar(i + 64);
        my_putchar(y + 48);
        write(1, ": missed\n\n", 10);
        kill(navy, SIGUSR1);
    }
    else {
        if (map[y - 1][i - 1] != '.' && map[y - 1][i - 1] != 'o') {
        map[y - 1][i - 1] = 'x';
        my_putchar(i + 64);
        my_putchar(y + 48);
        write(1, ": hit\n\n", 7);
        }
        kill(navy, SIGUSR2);
    }
}

int player_one_in_game(char **map, char **map_enemy)
{
    char *signal_enemy;

    while (1) {
        if (check_end(map, map_enemy) == 1 || check_end(map, map_enemy) == 0)
            return (check_end(map, map_enemy));
        send_signal(map_enemy);
        if (check_end(map, map_enemy) == 1 || check_end(map, map_enemy) == 0)
            return (check_end(map, map_enemy));
        signal_enemy = receive_signal(map, map_enemy);
        if (check_end(map, map_enemy) == 1 || check_end(map, map_enemy) == 0)
            return (check_end(map, map_enemy));
        display_map(map, "my positions:\n");
        display_map(map_enemy, "enemy's positions:\n");
        if (check_end(map, map_enemy) == 1 || check_end(map, map_enemy) == 0)
            return (check_end(map, map_enemy));
    }
}

int player_two_in_game(char **map, char **map_enemy)
{
    char *signal_enemy;

    while (1) {
        if (check_end(map, map_enemy) == 1 || check_end(map, map_enemy) == 0)
            return (check_end(map, map_enemy));
        signal_enemy = receive_signal(map, map_enemy);
        if (check_end(map, map_enemy) == 1 || check_end(map, map_enemy) == 0)
            return (check_end(map, map_enemy));
        send_signal(map_enemy);
        if (check_end(map, map_enemy) == 1 || check_end(map, map_enemy) == 0)
            return (check_end(map, map_enemy));
        display_map(map, "my positions:\n");
        display_map(map_enemy, "enemy's positions:\n");
        if (check_end(map, map_enemy) == 1 || check_end(map, map_enemy) == 0)
            return (check_end(map, map_enemy));
    }
}