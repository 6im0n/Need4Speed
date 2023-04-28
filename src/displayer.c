/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** IA
*/

#include "n4s.h"

void display_info(car_t *car)
{
    dprintf(2, "\e[1;32mSpeed:\e[0m %d \e[1;32mKm/H\e[0m\r", car->display_speed);
}