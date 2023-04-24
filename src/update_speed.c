/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** ia
*/

#include "n4s.h"

void update_speed(main_t *main)
{
    if (len_of_array(main->lidar) < 15)
        return;
    float distance = atof(main->lidar[14]);

    if ( distance >= 2000)
        main->speed = 0.8;
    else if (distance >= 1500)
        main->speed = 0.6;
    else if (distance >= 1000)
        main->speed = 0.4;
    else if (distance >= 600)
        main->speed = 0.3;
    else if (distance >= 400)
        main->speed = 0.2;
    else if (distance < 400)
        main->speed = 0.1;
}