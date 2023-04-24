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

// void turn(main_t *main, float direction)
// {
//     if (direction == main->direction)
//         return;
//     printf("WHEELS_DIR:%f\n", direction);
//     main->direction = direction;
// }
static void get_info(main_t *main)
{
    if (clock() - main->clock > 10000)
        main->clock = clock();
    else {
        return;
    }
    char *line = NULL;
    size_t len = 0;
    int read = 0;
    fflush(stdout);
    dprintf(2, "GET_INFO_LIDAR\n");
    dprintf(1, "GET_INFO_LIDAR\n");
    read = getline(&line, &len, stdin);
    if (read == -1)
        exit(84);
    main->lidar = split_str(line, ':');
}

static void start_simulation(void)
{
    size_t n = 0;
    char *buffer = NULL;
    fflush(stdout);
    dprintf(2,"START_SIMULATION\n");
    dprintf(1,"START_SIMULATION\n");
    getline(&buffer, &n, stdin);
}

int main(void)
{
    main_t main;
    main.clock = 0;
    main.speed = 0.2;
    main.old_speed = 0;
    start_simulation();
    sleep(1);
    while (1) {
        fflush(stdout);
        forward(&main);
        sleep(0.4);
        get_info(&main);
        update_speed(&main);
        sleep(0.4);
        stop_car_distance(&main, 450);
        if (main.stoped == 1){
            stop(&main);
            sleep(5);
            break;
        }
    }
    return 0;
}
