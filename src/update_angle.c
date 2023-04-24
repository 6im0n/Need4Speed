/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** ia
*/

#include "n4s.h"

static void get_angle(main_t *main, float distance)
{
    if (distance >= 1500){
        main->angle = 0.5;
        return;
    }
    if (distance >= 1000){
        main->angle = 0.07;
        return;
    }
    if (distance >= 600){
        main->angle = 0.1;
        return;
    }
    if (distance >= 400){
        main->angle = 0.4;
        return;
    }
    if (distance >= 200){
        main->angle = 0.8;
        return;
    }
    if (distance < 200 && distance >= 50){
        main->angle = 0.9;
        return;
    }
    else
        main->angle = 1;
}

void update_angle(main_t *main)
{
    if (len_of_array(main->lidar) < 15)
        return;
    float distance = atof(main->lidar[17]);
    float direction = (atof(main->lidar[3]) - atof(main->lidar[31]) < 0) ? -1 : 1;
    get_angle(main, distance);
    main->angle *= direction;
}
