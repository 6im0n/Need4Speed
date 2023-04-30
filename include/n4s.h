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
#include <string.h>

typedef struct vector2f_s {
    float left;
    float right;
} vector2f_t;

typedef struct car_s {
    int stoped;
    int display_speed;
    float speed;
    float old_speed;
    float angle;
    float old_angle;
    float direction;
    char **lidar;
} car_t;

char **split_str(char *input, char delimiter);

void verif_start(char *error);

void verif(void);

void stop(car_t *car);

void forward(car_t *car);

int track_cleared(car_t *car);

void update_speed(car_t *car);

int len_of_array(char **array);

void turn(car_t *car);

void update_angle(car_t *car);

void tools(car_t *car);

void display_info(car_t *car);

void stop_car_distance(car_t *car, float distance);
