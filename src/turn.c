/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** turn
*/

#include "n4s.h"

void turn(car_t *car)
{
    size_t n = 0;
    char *buffer = NULL;
    if (car->angle == car->old_angle)
        return;
    dprintf(1, "WHEELS_DIR:%.2f\n", car->angle);
    getline(&buffer, &n, stdin);
    car->old_angle = car->angle;
}
