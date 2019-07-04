/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** signal.c
*/

#include "../include/navy.h"

void write_info(char *info)
{
    int pid = getpid();

    write(1, "my_pid: ", 8);
    my_put_nbr(pid);
    write(1, info, my_strlen(info));
}

void get_pid(int sig, siginfo_t *info, void *ucontext)
{
    navy = info->si_pid;
}

void counter(int sig, siginfo_t *info, void *ucontext)
{
    navy = sig;
}

void def_sig(void)
{
    struct sigaction navy1;
    struct sigaction navy2;

    navy1.sa_flags = SA_SIGINFO;
    navy1.sa_sigaction = &counter;
    navy2.sa_flags = SA_SIGINFO;
    navy2.sa_sigaction = &get_pid;
    sigaction(SIGUSR1, &navy1, NULL);
    sigaction(SIGUSR2, &navy2, NULL);
}
