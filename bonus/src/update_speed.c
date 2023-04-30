/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** ia
*/

#include "n4s.h"

static vector2f_t next_to(car_t *car)
{
    vector2f_t next;

    next.right = atof(car->lidar[31]);
    next.left = atof(car->lidar[3]);
    return next;
}

static float get_distance(car_t *car)
{
    vector2f_t next = next_to(car);
    float distance = atof(car->lidar[17]);

    if (len_of_array(car->lidar) < 15)
        return car->speed;
    if (distance >= 300 || next.left >= 300 || next.right >= 300)
        car->speed = 0.25;
    else if (distance < 300 || next.left < 300 || next.right < 300)
        car->speed = 0.2;
    return distance;
}

void update_speed(car_t *car)
{
    float distance = get_distance(car);
    vector2f_t next = next_to(car);
    if (distance >= 2000){
        car->speed = 1.0;
        return;
    }
    if (distance >= 1500){
        car->speed = 0.9;
        return;
    }
    if (distance >= 1000){
        car->speed = 0.4;
        return;
    }
    if (distance >= 600){
        car->speed = 0.3;
        return;
    }
    if (distance >= 400 || next.left >= 400 || next.right >= 400)
        car->speed = 0.2;
}
