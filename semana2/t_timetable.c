#include <stdio.h>
#include <stdlib.h>
#include "t_timetable.h"

void print(Timetable *timetable){
    for(int i = 0; i < timetable->size; i++){
        printf("| %s | %3s |\n", timetable->time[i].hour, timetable->time[i].minute, timetable->time[i].second, timetable->name[i]);
    }
}

Timetable* malloc_timetable(){
    Timetable *timetable = (Timetable*) malloc(sizeof(Timetable));
    timetable->time = (Time*) malloc(sizeof(Time));
    timetable->name = (char*) malloc(sizeof(char));
    return timetable;
}

// Para testes
void main(){

}