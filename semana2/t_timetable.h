#ifndef __T_TIMETABLE_H__
#define __T_TIMETABLE_H__
#include "t_time.h"

#define NAME_LEN 100
typedef struct t_timetable Row;
// Prof aqui eu mantive o nome original da estrutura que o senhor pediu
// Porém ele estava me confundido, então o senhor vai ver que logo acima eu renomeei
// para Row
struct t_timetable {
    Time *time;
    char *name;
};

void print_row(Row *row);
Row * create_row(Time *time, char *name);
#endif