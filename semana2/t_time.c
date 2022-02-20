#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "t_time.h"

void print_time(Time *time){
    char str[TIME_LEN];
    time_to_string(time, str);
    printf("%s", str);
}

Time *malloc_time() {
    Time *time = (Time *) malloc(sizeof(Time));
    return time;
}

Time *create_time(int hour, int minutes, int seconds) {
    Time *time = malloc_time();
    time->hour = hour;
    time->minute = minutes;
    time->second = seconds;
    return time;
}

// Se time1 for maior, retorna 1.
// Caso contrário, -1. 
// Se igual, 0.
int time_cmp(Time* time1, Time* time2){
    int time1_in_seconds = time_to_seconds(time1);
    int time2_in_seconds = time_to_seconds(time2);

    if (time1_in_seconds > time2_in_seconds){
        return 1;
    }else if(time1_in_seconds < time2_in_seconds){
        return -1;
    }else{
        return 0;
    }
}

int greater(Time *time1, Time *time2)
{
    return time_cmp(time1, time2) > 0;
}

int lesser(Time *time1, Time *time2)
{
    return time_cmp(time1, time2) < 0;
}

int equal(Time *time1, Time *time2)
{
    return time_cmp(time1, time2) == 0;
}

void time_to_string(Time* time, char *dest){
    char buffer[TIME_LEN] = {};
    snprintf(buffer, TIME_LEN, "%02d:%02d:%02d", time->hour, time->minute, time->second);
    strncpy(dest, buffer, TIME_LEN);
}

int time_to_seconds(Time *time){
    return 3600 * time->hour + 60 * time->minute + time->second;
}

// Para testes
// int main(){
//     Time *time = create_time(12, 13, 14);
//     char stringyfied[TIME_LEN] = {};
//     time_to_string(time, stringyfied);
//     printf("%s\n", stringyfied);

//     printf("%d\n", time_to_seconds(time));

//     Time *greater_by_seconds = create_time(12, 13, 13);
//     Time *greater_by_minutes = create_time(12, 12, 14);
//     Time *greater_by_hours = create_time(11, 13, 14);
//     Time *equal = create_time(12, 13, 14);

//     printf("Maior por segundos: %d\n", time_cmp(time, greater_by_seconds));
//     printf("Maior por minutos:%d\n", time_cmp(time, greater_by_minutes));
//     printf("Maior por horas: %d\n", time_cmp(time, greater_by_hours));
//     printf("Igual: %d\n", time_cmp(time, equal));

//     Time *less_by_seconds = create_time(12, 13, 15);
//     Time *less_by_minutes = create_time(12, 14, 14);
//     Time *less_by_hours = create_time(13, 13, 14);

//     printf("Menor por segundos: %d\n", time_cmp(time, less_by_seconds));
//     printf("Menor por minutos:%d\n", time_cmp(time, less_by_minutes));
//     printf("Menor por horas: %d\n", time_cmp(time, less_by_hours));
// }