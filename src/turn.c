/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** turn
*/

#include "n4s.h"

void turn(main_t *main)
{
    size_t n = 0;
    char *buffer = NULL;
    if (main->angle == main->old_angle)
        return;
    fflush(stdout);
    dprintf(2, "WHEELS_DIR:%.1f\n", main->angle);
    dprintf(1, "WHEELS_DIR:%.1f\n", main->angle);
    getline(&buffer, &n, stdin);
    main->old_angle = main->angle;
}