/*
** EPITECH PROJECT, 2018
** real_navy
** File description:
** navy.h
*/

#ifndef NAVY_H
#define NAVY_H
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//signal.c
void write_info(char *info);
void get_pid(int sig, siginfo_t *info, void *ucontext);
void counter(int sig, siginfo_t *info, void *ucontext);
void def_sig(void);

//game_in_play.c
int send_signal(char **map_enemy);
char *receive_signal(char **map, char **map_enemy);
void change_map_after_signal(char **map, int y, int i, int z);
int player_one_in_game(char **map, char **map_enemy);
int player_two_in_game(char **map, char **map_enemy);

//map_in_game2.c
int change_map_enemy(char **map_enemy, char *attack);
int count_hit(char **map);
int check_attack(char *attack);
int check_end(char **map, char **map_enemy);

//make_map.c
void display_map(char **map, char *perso);
char **create_map(void);
char **open_pos(char *filepath);
char **change_map(char **map, char *filepath);
char **make_map(char *filepath);

//get_next_line.c
int my_strlen(char *str);
int check_n(char const *str);
char *str_cat(char *filepath, char *filepath_2);
char *get_next_line(int fd);

//my_put_nbr.c
void my_putchar(char c);
int find_digit(int x);
void disp_val(int v);
void my_put_nbr(int nb);
int my_getnbr(char const *str);
volatile int navy;
#endif