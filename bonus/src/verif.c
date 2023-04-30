/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** IA
*/

#include "n4s.h"

void verif_start(char *error)
{
    char **tab = split_str(error, ':');

    switch (atoi(tab[0])) {
    case 1:
        dprintf(2, "\e[1;33mSimulation Started !\e[0m\n");
        break;
    default:
        dprintf(2, "\e[1;33mError: %s\e[0m\n", tab[2]);
        break;
    }
    free(tab);
}

void verif(void)
{
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    char **tab = split_str(line, ':');
    if (atoi(tab[0]) == 1)
        return;
    else
        dprintf(2, "\e[1;33mError: %s\e[0m\n", tab[2]);
    free(tab);
}
