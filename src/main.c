/*
** EPITECH PROJECT, 2023
** indroduction to IA
** File description:
** N4S
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct main_s {
    float speed;
    int direction;
    int stoped;
    char **lidar;
    clock_t clock;
} main_t;

char **split_str(char *input, char delimiter);

int len_of_array(char **array)
{
    int i = 0;
    while (array[i] != NULL){
        i++;
    }
    return i;
}

void forward(main_t *main, float speed)
{
    if (speed == main->speed)
        return;
    fflush(stdout);
    printf("CAR_FORWARD:%.1f\n", speed);
    dprintf(2,"CAR_FORWARD:%.1f\n", speed);
    main->speed = speed;
}

void stop(main_t *main)
{
    write(1,"CAR_BACKWARDS:0\n", 16);
    dprintf(2,"CAR_FORWARD:0\n");
    main->speed = 0;
    main->stoped = 1;
}

void turn(main_t *main, float direction)
{
    if (direction == main->direction)
        return;
    printf("WHEELS_DIR:%f\n", direction);
    main->direction = direction;
}

void get_info(main_t *main)
{
    if (clock() - main->clock  > 10000)
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

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;
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
