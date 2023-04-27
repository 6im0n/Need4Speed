/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** ia
*/

#include "n4s.h"

static float get_distance(car_t *car)
{
    if (len_of_array(car->lidar) < 15)
        return car->speed;
    float distance = atof(car->lidar[17]);
    if (distance >= 300)
        car->speed = 0.3;
    else if (distance < 300)
        car->speed = 0.2;
    return distance;
}

void update_speed(car_t *car)
{
    float distance = get_distance(car);
    if (distance >= 2000){
        car->speed = 1.0;
        return;
    }
    if (distance >= 1500){
        car->speed = 0.8;
        return;
    }
    if (distance >= 1000){
        car->speed = 0.6;
        return;
    }
    if (distance >= 600){
        car->speed = 0.5;
        return;
    }
    if (distance >= 400)
        car->speed = 0.4;
}
