#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t_timetable.h"

void print_row(Row *row){
    printf("| ");
    print_time(row->time);
    printf(" | %30s |\n", row->name);
}

Row* malloc_row(){
    Row *row = (Row*) malloc(sizeof(Row));
    row->time = NULL;
    row->name = (char *) malloc(NAME_LEN *sizeof(char));
    return row;
}

Row * create_row(Time *time, char *name){
    Row *row = malloc_row();
    row->time = time;
    memset( row->name, 0x00, NAME_LEN );
    strncpy(row->name, name, strlen(name));
//    row->name = name;
    return row;
}

// // Para testes 
// void main() {
//     Row *row = create_row(create_time(12, 13, 14), "Teste");
//     print_row(row);
// }