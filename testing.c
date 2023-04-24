/*
** EPITECH PROJECT, 2023
** IA introduction
** File description:
** need4steck
*/
#include "n4s.h"

void forward_car(simu_t *simu, float speed)
{
    if (simu->speed == speed)
        return;
    dprintf(1,"CAR_FORWARD:%.1f\n", speed);
    simu->speed = speed;
}


void bacward_car(simu_t *simu, float speed)
{
    if (simu->speed == -speed)
        return;
    dprintf(1,"CAR_BACKWARDS:%.1f\n", speed);
    simu->speed = -speed;
}

void car_stop(simu_t *simu)
{
    if (simu->speed == 0)
        return;
    write(1, "CAR_FORWARD:0\n", strlen("CAR_FORWARD:0\n"));
    simu->speed = 0;
}

int main(int argc, char const *argv[])
{
    simu_t simu;
    simu.status = 0;
    simu.speed = 0;
    simu.angle = 0;

    start_program();
    write(2,"info: runing !",14);
    while (1){
        if (simu.status == 1){
            //bacward_car(&simu, 1.0);
            car_stop(&simu);
            sleep(0.02); // utilisation de sleep en attedant de faire un system qui verifie ce que renvoie l'api aprés l'envoie d'une commade. (ok/ko)
        }
        else {
            sleep(0.02);
            forward_car(&simu, 0.7);
            sleep(0.02);
            check_state(&simu);
            sleep(0.02);
            check_pos(&simu);
        }
    }
    return 0;
}


void start_program(void)
{
    write(1, "START_SIMULATION\n", strlen("START_SIMULATION\n"));
}

void check_pos(simu_t *simu)
{
    write(1, "GET_INFO_LIDAR\n", strlen("GET_INFO_LIDAR\n"));
    char *buffer = NULL;
    size_t size;
    getline(&buffer, &size, stdin);
    char **tab = split_str(buffer, ':');
    if (tab[29]){
        float dist = (atof(tab[16]) + atof(tab[17]))/2;
        dprintf(2,"%f",dist);
        if ( dist < 1200) {
            simu->status = 1;
        }
    }
    free(buffer);
    free(tab);
}
void check_state(simu_t *simu)
{
    write(1, "GET_INFO_SIMTIME\n", strlen("GET_INFO_SIMTIME\n"));
    char *buffer = NULL;
    size_t size;
    getline(&buffer, &size, stdin);
    char **state = split_str(buffer, ':');
    if (state[4]){
        if (strcmp(state[4], "Track Cleared") == 0) {
            simu->status = 1;
        }
    }
    free(buffer);
    free(state);
}