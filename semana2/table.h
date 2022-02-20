#ifndef __TABLE_H__
#define __TABLE_H__
#include "t_timetable.h"

typedef struct Table Table;

struct Table{
    int size;
    int max;
    Row *rows;
};
void print_table(Table *table);
Table *create_table();
void realloc_table(Table *table);
void shift_left(Table *table, int starting_point);

void put(Table *table, Row *row);
char* get(Table *table, Time *time); //DONE
void delete(Table *table, Time *time); //DONE
int contains(Table *table, Time *time);
int is_empty(Table *table);
int size(Table *table);
Time* min(Table *table);
Time* max(Table *table);
Time* floor(Table *table, Time *time);
Time* ceiling(Table *table, Time *time);
int rank(Table *table, Time *time); // Posição na tabela (a partir da menor)
//Time* select(Table *table, int k); // k-ésimo elemento (a partir da menor)
void delete_min(Table *table);
void delete_max(Table *table);
int size_range(Table *table, Time *lo, Time *hi);
void keys(Table *table, Time *lo, Time *hi);

#endif