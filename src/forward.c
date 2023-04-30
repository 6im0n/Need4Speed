/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** turn
*/

#include "n4s.h"

void forward(car_t *car)
{
    if (car->speed == car->old_speed)
        return;
    dprintf(1, "CAR_FORWARD:%.2f\n", car->speed);
    verif();
    car->old_speed = car->speed;
}
