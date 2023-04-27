/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** ia
*/

#include "n4s.h"

int len_of_array(char **array)
{
    int i = 0;
    while (array[i] != NULL){
        i++;
    }
    return i;
}

void stop_car_distance(car_t *car, float distance)
{
    if (car->lidar == NULL)
        return;
    if (len_of_array(car->lidar) < 7)
        return;
    if (atof(car->lidar[17]) <= distance){
        stop(car);
        car->stoped = 1;
    } else
        return;
}

int track_cleared(car_t *car)
{
    if (strcmp(car->lidar[35], "Track Cleared") == 0) {
        stop(car);
        return 1;
    }
    return 0;
}

void stop(car_t *car)
{
    size_t n = 0;
    char *buffer = NULL;

    write(1,"CAR_BACKWARDS:0\n", 16);
    dprintf(2,"CAR_FORWARD:0\n");
    getline(&buffer, &n, stdin);
    dprintf(1, "stop_simulation\n");
    car->speed = 0;
    car->stoped = 1;
}
