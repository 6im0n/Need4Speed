/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** ia
*/

#include "n4s.h"

static void get_angle(car_t *car, float distance)
{
    if (distance >= 1500){
        car->angle = 0.01;
        return;
    } if (distance >= 1000){
        car->angle = 0.05;
        return;
    } if (distance >= 600){
        car->angle = 0.1;
        return;
    } if (distance >= 400){
        car->angle = 0.2;
        return;
    } if (distance >= 200){
        car->angle = 0.3;
        return;
    } if (distance < 200 && distance >= 50){
        car->angle = 0.7;
        return;
    } else
        car->angle = 1;
}

void update_angle(car_t *car)
{
    if (len_of_array(car->lidar) < 15)
        return;
    float distance = atof(car->lidar[17]);
    float dir = (atof(car->lidar[3]) - atof(car->lidar[31]) < 0) ? -1 : 1;
    get_angle(car, distance);
    car->angle *= dir;
}
