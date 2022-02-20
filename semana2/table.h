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
void shift_right(Table *table, int end_point);

void put(Table *table, Row *row);
char* get(Table *table, Time *time); //DONE
void delete(Table *table, Time *time); //DONE
int contains(Table *table, Time *time); // DONE
int is_empty(Table *table); // DONE
int size(Table *table); // DONE 
Time* min(Table *table); // DONE
Time* max(Table *table); // DONE
Time* floor(Table *table, Time *time); // DONE
Time* ceiling(Table *table, Time *time); // DONE
int rank(Table *table, Time *time); // DONE
Time* select_by_rank(Table *table, int k); // DONE Professor precisei renomear pois tava dando conflito com o nome de uma
// função da stdlib, e por isso não conseguia compilar.
void delete_min(Table *table); // DONE
void delete_max(Table *table); // DONE
int size_range(Table *table, Time *lo, Time *hi); // DONE
void keys(Table *table, Time *lo, Time *hi);

#endif