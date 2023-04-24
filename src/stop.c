/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** ia
*/

#include "n4s.h"

static int len_of_array(char **array)
{
    int i = 0;
    while (array[i] != NULL){
        i++;
    }
    return i;
}

void stop_car_distance(main_t *main, float distance)
{
    if (main->lidar == NULL)
        return;
    if (len_of_array(main->lidar) < 7)
        return;
    if (atof(main->lidar[17]) <= distance){
        stop(main);
        main->stoped = 1;
    } else
        return;
}

void stop(main_t *main)
{
    write(1,"CAR_BACKWARDS:0\n", 16);
    dprintf(2,"CAR_FORWARD:0\n");
    main->speed = 0;
    main->stoped = 1;
}
