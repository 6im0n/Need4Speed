/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** IA
*/

#include "n4s.h"

static void speedometer(car_t *car)
{
    (void) car;
    size_t n = 0;
    char *buffer = NULL;
    char **speed;
    dprintf(1, "GET_CURRENT_SPEED\n");
    getline(&buffer, &n, stdin);
    speed = split_str(buffer, ':');
    car->display_speed = atoi(speed[3]);
}

void tools(car_t *car)
{
    speedometer(car);
}
