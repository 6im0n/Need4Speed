/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** IA
*/

#include "n4s.h"

static void forward(main_t *main, float speed)
{
    if (speed == main->speed)
        return;
    fflush(stdout);
    printf("CAR_FORWARD:%.1f\n", speed);
    dprintf(2,"CAR_FORWARD:%.1f\n", speed);
    main->speed = speed;
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
    write(1,"GET_INFO_LIDAR\n", 15);
    dprintf(2,"GET_INFO_LIDAR\n");
    read = getline(&line, &len, stdin);
    if (read == -1)
        exit(84);
    main->lidar = split_str(line, ':');
}

int main(void)
{
    main_t main;
    main.clock = 0;
    write(1,"START_SIMULATION\n", 17);
    dprintf(2,"START_SIMULATION\n");
    sleep(1);
    while (1) {
        fflush(stdout);
        forward(&main, 0.5);
        sleep(0.4);
        get_info(&main);
        sleep(0.4);
        stop_car_distance(&main, 2000);
        if (main.stoped == 1){
            stop(&main);
            sleep(5);
            break;
        }
    }
    return 0;
}
