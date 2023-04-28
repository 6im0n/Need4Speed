/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** turn
*/

#include "n4s.h"

void forward(car_t *car)
{
    size_t n = 0;
    char *buffer = NULL;
    if (car->speed == car->old_speed)
        return;
    dprintf(1, "CAR_FORWARD:%.2f\n", car->speed);
    getline(&buffer, &n, stdin);
    car->old_speed = car->speed;
}
