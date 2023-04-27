/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** IA
*/

#include "n4s.h"

static void init_struct(car_t *car)
{
    car->speed = 0.5;
    car->old_speed = 0;
    car->angle = 0;
    car->old_angle = 0;
    car->direction = 0;
}

static void get_info(car_t *car)
{
    char *line = NULL;
    size_t len = 0;
    int read = 0;
    dprintf(2, "#GET_INFO_LIDAR\n");
    dprintf(1, "GET_INFO_LIDAR\n");
    read = getline(&line, &len, stdin);
    if (read == -1)
        exit(84);
    car->lidar = split_str(line, ':');
}

static void start_simulation(void)
{
    size_t n = 0;
    char *buffer = NULL;

    dprintf(2,"#START_SIMULATION\n");
    dprintf(1,"START_SIMULATION\n");
    getline(&buffer, &n, stdin);
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
        forward(&car);
        turn(&car);
        track_cleared(&car);
        if (car.stoped == 1){
            dprintf(2, "#STOP_SIMULATION\n");
            sleep(5);
            break;
        }
    }
    return 0;
}
