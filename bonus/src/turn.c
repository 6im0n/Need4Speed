/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** turn
*/

#include "n4s.h"

void turn(car_t *car)
{
    if (car->angle == car->old_angle)
        return;
    dprintf(1, "WHEELS_DIR:%.2f\n", car->angle);
    verif();
    car->old_angle = car->angle;
}
