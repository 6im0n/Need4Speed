/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** IA
*/

#include "n4s.h"

static void get_info(car_t *car)
{
    char *line = NULL;
    size_t len = 0;

    dprintf(1, "GET_INFO_LIDAR\n");
    getline(&line, &len, stdin);
    car->lidar = split_str(line, ':');
}

static void fail(car_t *car)
{
    float dis_f = atof(car->lidar[17]);
    float dis_r = atof(car->lidar[3]);
    float dis_l = atof(car->lidar[31]);

    if (dis_f < 100 || dis_r < 100 || dis_l < 100){
        car->angle = -(car->angle);
        turn(car);
        dprintf(1, "CAR_BACKWARDS:0.3\n");
        verif();
        car->speed = -0.5;
        car->angle = -(car->angle);
        get_info(car);
        fail(car);
    }
    return;
}

static void init_struct(car_t *car)
{
    car->speed = 0.5;
    car->old_speed = 0;
    car->angle = 0;
    car->old_angle = 0;
    car->direction = 0;
}

static void start_simulation(void)
{
    size_t n = 0;
    char *buffer = NULL;
    int read = 0;

    dprintf(2, "\e[1;33mWait app load ...\e[0m\n");
    dprintf(1,"START_SIMULATION\n");
    read = getline(&buffer, &n, stdin);
    verif_start(buffer);
    if (read == -1)
        exit(84);
}

int main(void)
{
    car_t car;
    init_struct(&car);
    start_simulation();
    while (1) {
        get_info(&car);
        update_speed(&car);
        update_angle(&car);
        fail(&car);
        forward(&car);
        turn(&car);
        track_cleared(&car);
        tools(&car);
        display_info(&car);
        if (car.stoped == 1){
            dprintf(2, "\e[1;31mSimulation Stoped !\e[0m\n");
            sleep(5);
            break;
        }
    }
    return 0;
}
