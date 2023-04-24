/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** IA
*/

#include "n4s.h"

static void forward(main_t *main)
{
    size_t n = 0;
    char *buffer = NULL;
    if (main->speed == main->old_speed)
        return;
    fflush(stdout);
    dprintf(2, "CAR_FORWARD:%.1f\n", main->speed);
    dprintf(1, "CAR_FORWARD:%.1f\n", main->speed);
    getline(&buffer, &n, stdin);
    main->old_speed = main->speed;
}

static void get_info(main_t *main)
{
    char *line = NULL;
    size_t len = 0;
    int read = 0;
    fflush(stdout);
    dprintf(2, "#GET_INFO_LIDAR\n");
    dprintf(1, "GET_INFO_LIDAR\n");
    read = getline(&line, &len, stdin);
    if (read == -1)
        exit(84);
    main->lidar = split_str(line, ':');
}

static void start_simulation(main_t *main)
{
    main->speed = 0.2;
    main->old_speed = 0;
    main->angle = 0;
    main->old_angle = 0;
    main->direction = 0;
    size_t n = 0;
    char *buffer = NULL;

    fflush(stdout);
    dprintf(2,"#START_SIMULATION\n");
    dprintf(1,"START_SIMULATION\n");
    getline(&buffer, &n, stdin);
}

int main(void)
{
    main_t main;
    start_simulation(&main);
    while (1) {
        fflush(stdout);
        forward(&main);
        get_info(&main);
        update_speed(&main);
        update_angle(&main);
        turn(&main);
        stop_car_distance(&main, 100);
        if (main.stoped == 1){
            stop(&main);
            dprintf(2, "#STOP_SIMULATION\n");
            sleep(5);
            break;
        }
    }
    return 0;
}
