/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** get_next_line.c
*/

#include "../include/navy.h"

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int check_n(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            return (i);
    return (-1);
}

char *str_cat(char *filepath, char *filepath_2)
{
    char *file_end = malloc(my_strlen(filepath) + my_strlen(filepath_2) + 2);
    int y = 0;

    for (int i = 0; filepath[i] != '\0'; i++) {
        file_end[y] = filepath[i];
        y++;
    }
    for (int z = 0; filepath_2[z] != '\0'; z++) {
        file_end[y] = filepath_2[z];
        y++;
    }
    file_end[y] = '\0';
    return (file_end);
}

char *get_next_line(int fd)
{
    char *buffer = malloc(1001);
    char *line = "\0";
    int i = 0;

    buffer[read(fd, buffer, 1000)] = '\0';
    line = str_cat(line, buffer);
    while (check_n(line) == -1) {
        buffer[read(fd, buffer, 1000)] = '\0';
        line = str_cat(line, buffer);
    }
    line[check_n(line)] = '\0';
    return (line);
}