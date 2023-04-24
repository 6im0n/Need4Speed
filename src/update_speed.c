/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** ia
*/

#include "n4s.h"

static float get_distance(main_t *main)
{
    if (len_of_array(main->lidar) < 15)
        return main->speed;
    float distance = atof(main->lidar[14]);
    if (distance < 400)
        main->speed = 0.1;
    return distance;
}
void update_speed(main_t *main)
{
    float distance = get_distance(main);
    if (distance >= 2000){
        main->speed = 0.8;
        return;
    }
    if (distance >= 1500){
        main->speed = 0.6;
        return;
    }
    if (distance >= 1000){
        main->speed = 0.4;
        return;
    }
    if (distance >= 600){
        main->speed = 0.3;
        return;
    }
    if (distance >= 400)
        main->speed = 0.2;
}
