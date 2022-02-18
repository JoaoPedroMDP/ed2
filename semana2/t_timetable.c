#include <stdio.h>
#include <stdlib.h>
#include "t_timetable.h"

void print_row(Row *row){
    printf("| %d:%d:%d | %30s |\n", row->time->hour, row->time->minute, row->time->second, row->name);
}

Row* malloc_row(){
    Row *row = (Row*) malloc(sizeof(Row));
    row->time = NULL;
    row->name = NULL;
    return row;
}

Row * create_row(Time *time, char *name){
    Row *row = malloc_row();
    row->time = time;
    row->name = name;
    return row;
}

// // Para testes 
// void main() {
//     Row *row = create_row(create_time(12, 13, 14), "Teste");
//     print_row(row);
// }