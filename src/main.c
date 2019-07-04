/*
** EPITECH PROJECT, 2018
** real_navy
** File description:
** main.c
*/

#include "../include/navy.h"

int player_one(char **av)
{
    char **map;
    char **map_enemy;

    map = make_map(av[1]);
    if (map == NULL)
        return (84);
    map_enemy = create_map();
    write_info("\nwaiting for enemy connection...\n");
    pause();
    write(1, "\nenemy connected\n\n", 18);
    display_map(map, "my positions:\n");
    display_map(map_enemy, "enemy's positions:\n");
    return (player_one_in_game(map, map_enemy));
}

int player_two(char **av)
{
    char **map;
    char **map_enemy;

    map = make_map(av[2]);
    if (map == NULL)
        return (84);
    map_enemy = create_map();
    write_info("\n");
    kill(my_getnbr(av[1]), SIGUSR2);
    usleep(2000);
    write(1, "successfully connected\n\n", 24);
    display_map(map, "my positions:\n");
    display_map(map_enemy, "enemy's positions:\n");
    return (player_two_in_game(map, map_enemy));
}

int check_error(int ac, char **av)
{
    def_sig();
    int fd;

    if (ac != 2 && ac != 3)
        return (84);
    if (ac == 2)
        fd = open(av[1], O_RDONLY);
    else if (ac == 3)
        fd = open(av[2], O_RDONLY);
    if (fd == -1)
        return (84);
}

void display_help(void)
{
    write(1, "USAGE\n     ./navy [first_player_pid] navy_positions\n", 52);
    write(1, "DESCRIPTION\n     first_player_pid:  ", 36);
    write(1, "only for the 2nd player.  pid of the first player.\n", 51);
    write(1, "     navy_positions:  ", 22);
    write(1, "file representing the positions of the ships.\n", 46);
}

int main(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h')
        display_help();
    if (check_error(ac, av) == 84)
        return (84);
    if (ac == 2) {
        if (player_one(av) == 1) {
            write(1, "Enemy win\n", 10);
            return (1);
        }
        else
            write(1, "I won\n", 6);
    }
    else if (ac == 3) {
        if (player_two(av) == 1) {
            write(1, "Enemy win\n", 10);
            return (1);
        }
        else
            write(1, "I won\n", 6);
    }
}
