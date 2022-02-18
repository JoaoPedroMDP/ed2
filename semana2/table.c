#include <stdio.h>
#include <stdlib.h>
#include "table.h"

void print_table(Table *table)
{
    for( int i = 0; i < table->size; i++)
    {
        print_row(&(table->rows[i])); // Pois rows é um array de structs, e não um array de ponteiros de structs, der.
    }
}

Table *malloc_table(){
    Table *table = (Table*) malloc(sizeof(Table));
    table->size = 0;
    table->max = 50;
    table->rows = (Row *) malloc(sizeof(Row) * table->max);
    return table;
}

Table *create_table(){
    return malloc_table();
}

void realloc_table(Table *table)
{
    int new_size = (int) table->size * 1.40;
    table->rows = (Row*) realloc(table->rows, new_size * sizeof(Row));
    table->max = new_size;
}

void put(Table *table, Row *row)
{
    if(table->size == table->max)
    {
        realloc_table(table);
    }

    table->rows[table->size] = *row;
    table->size++;
}

void main()
{
    Time *time1 = create_time(12,13,14);
    Row *row1 = create_row(time1, "Horaaaaaaaaaaaaaario");
    Time *time2 = create_time(15,16,17);
    Row *row2 = create_row(time2, "Oi");
    Table *table = create_table();

    for(int i = 0; i < 30; i++)
    {
        put(table, row1);
        put(table, row2);
    }
    print_table(table);
}