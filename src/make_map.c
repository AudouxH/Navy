/*
** EPITECH PROJECT, 2018
** real_navy
** File description:
** make_map.c
*/

#include "../include/navy.h"

void display_map(char **map, char *perso)
{
    write(1, perso, my_strlen(perso));
    write(1, " |A B C D E F G H\n-+---------------\n", 36);
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1);
        write(1, "|", 1);
        for (int y = 0; y < 8; y++) {
            write(1, &map[i][y], 1);
            if (y != 7)
                write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}

char **create_map(void)
{
    char **map = malloc(sizeof(char *) * 8);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 8);
        for (int y = 0; y < 8; y++)
            map[i][y] = '.';
    }
    return (map);
}

char **open_pos(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int x = 0;
    char *buffer = malloc(32);
    char **pos = malloc(sizeof(char *) * 4);

    read(fd, buffer, 32);
    for (int i = 0; i < 4; i++) {
        pos[i] = malloc(sizeof(char) * 8);
        for (int y = 0; y < 8; y++) {
            pos[i][y] = buffer[x];
            x++;
        }
    }
    return (pos);
}

char **change_map(char **map, char *filepath)
{
    char **pos = open_pos(filepath);
    int nb_boat = 0;
    int line2 = 0;
    int line = 0;
    int cols2 = 0;
    int cols = 0;

    for (int i = 0; i < 4; i++) {
        nb_boat = (pos[i][0] - 48);
        cols = (pos[i][3] - 48);
        cols2 = (pos[i][6] - 48);
        if ((line = (pos[i][2] - 64)) != (line2 = (pos[i][5] - 64)))
            for (; line <= line2; line++)
                map[cols - 1][line - 1] = nb_boat + 48;
        if (cols != cols2)
            for (; cols <= cols2; cols++)
                map[cols - 1][line - 1] = nb_boat + 48;
    }
    return (map);
}

char **make_map(char *filepath)
{
    char **map = create_map();

    map = change_map(map, filepath);
    return (map);
}
