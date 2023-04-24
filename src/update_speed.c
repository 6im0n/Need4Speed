/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** ia
*/

#include "n4s.h"

void update_speed(main_t *main)
{
    float distance = atof(main->lidar[14]);
    if distance >= 2500
        main->speed = 0.8;
    else if distance >= 2000
        main->speed = 0.75;
    else if distance >= 1500
        main->speed = 0.6;
    else if distance >= 1000
        main->speed = 0.4;
    else if distance >= 500
        main->speed = 0.25;
    else if distance >= 350
        main->speed = 0.1;
    else if distance >= 200
        main->speed = 0.07;
}