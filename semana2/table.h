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

void put(Table *table, Row *row);
char* get(Row *row, Time *time);
void delete(Row *row, Time *time);
int contains(Row *row, Time *time);
int is_empty(Row *row);
int size(Row *row);
Time* min(Row *row);
Time* max(Row *row);
Time* floor(Row *row, Time *time);
Time* ceiling(Row *row, Time *time);
int rank(Row *row, Time *time); // Posição na tabela (a partir da menor)
//Time* select(Row *row, int k); // k-ésimo elemento (a partir da menor)
void delete_min(Row *row);
void delete_max(Row *row);
int size_range(Row *row, Time *lo, Time *hi);
void keys(Row *row, Time *lo, Time *hi);

#endif