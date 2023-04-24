/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** ia
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct main_s {
    float speed;
    float old_speed;
    int direction;
    int stoped;
    char **lidar;
    clock_t clock;
} main_t;

char **split_str(char *input, char delimiter);

void stop(main_t *main);

void update_speed(main_t *main);

int len_of_array(char **array);

void stop_car_distance(main_t *main, float distance);
