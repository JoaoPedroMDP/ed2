#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "table.h"

// Mostra a tabela
void print_table(Table *table)
{
    for( int i = 0; i < table->size; i++)
    {
        print_row(&(table->rows[i])); // Pois rows é um array de structs, e não um array de ponteiros de structs, der.
    }
}

// Aloca espaço para a tabela (apenas na criação)
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

// Realoca espaço para a tabela
void realloc_table(Table *table)
{
    int new_size = (int) table->size * 1.40;
    table->rows = (Row*) realloc(table->rows, new_size * sizeof(Row));
    table->max = new_size;
}

// Inserte uma linha na tabela ordenadamente.
void put(Table *table, Row *row)
{
    int i = 0;
    if(table->size == table->max)
    {
        realloc_table(table);
    }

    while(i < table->size && table->rows[i].time != NULL && greater(row->time, table->rows[i].time)){
        i++;
    }

    shift_right(table, i);
    table->rows[i] = *row;
}

// Retorna o valor da primeira posição com a chave passada
char *get(Table *table, Time *time)
{
    for( int i = 0; i < table->size; i++){
        if(time_cmp(table->rows[i].time, time) == 0){
            return table->rows[i].name;
        }
    }
    printf("Não encontrado\n");
    return NULL;
}

// Move o array para a esquerda começando em starting_point (este será removido)
void shift_left(Table *table, int starting_point)
{
    int i = 0;
    for (i = starting_point; i < table->size - 1; i++)
    {
        table->rows[i] = table->rows[i + 1];
    }

    table->size--;
}

// Move o array para a direita começando do fim até end_point
void shift_right(Table *table, int end_point)
{
    if(table->size == table->max){
        printf("Tabela cheia. Realocando...\n");
        realloc_table(table);
    }

    int i = 0;
    for (i = table->size; i >= end_point; i--)
    {
        table->rows[i] = table->rows[i - 1];
    }

    table->size++;
}

// Tanto delete como contains faziam quase a mesma coisa, então puxei pra cima o trabalho pesado
int find(Table *table, Time *time)
{
    for( int i = 0; i < table->size; i++){
        if(time_cmp(table->rows[i].time, time) == 0){
            return i;
        }
    }

    printf("Não encontrado\n");
    return -1;
}

// Remove o elemento da tabela
void delete(Table *table, Time *time)
{
    int index = find(table, time);
    if(index >= 0){
        shift_left(table, index);
    }
}

// Verifica se a tabela contém o elemento passado
int contains(Table *table, Time *time)
{
    int index = find(table, time);
    return index >= 0;
}

// Verifica se a tabela está vazia
int is_empty(Table *table)
{
    return table->size == 0;
}


int size(Table *table)
{
    return table->size;
}

Time *min(Table *table)
{
    Time *min = create_time(INT_MAX, INT_MAX, INT_MAX);
    for(int i = 0; i < table->size; i++){
        if(time_cmp(table->rows[i].time, min) <= 0){
            min = table->rows[i].time;
        }
    }

    return min;
}

Time *max(Table *table)
{
    Time *max = create_time(INT_MIN, INT_MIN, INT_MIN);
    for(int i = 0; i < table->size; i++){
        if(time_cmp(table->rows[i].time, max) >= 0){
            max = table->rows[i].time;
        }
    }

    return max;
}

Time *floor(Table *table, Time *time)
{
    int i = 0;
    Time *floor = create_time(INT_MIN, INT_MIN, INT_MIN);
    for( i = 0; i < table->size; i++)
    {
        if((lesser(table->rows[i].time, time) || equal(table->rows[i].time, time)) && greater(table->rows[i].time, floor)){
            floor = table->rows[i].time;
        }
    }

    return floor;
}

Time *ceiling(Table *table, Time *time)
{
    int i = 0;
    Time *floor = create_time(INT_MAX, INT_MAX, INT_MAX);
    for( i = 0; i < table->size; i++)
    {
        if((greater(table->rows[i].time, time) || equal(table->rows[i].time, time)) && lesser(table->rows[i].time, floor)){
            floor = table->rows[i].time;
        }
    }

    return floor;
}

int rank(Table *table, Time *time)
{
    int i = 0;
    int rank = 0;
    for( i = 0; i < table->size; i++)
    {
        if(lesser(table->rows[i].time, time)){
            rank++;
        }
    }

    return rank;
}

Time *select_by_rank(Table *table, int rank)
{
    if(rank < table->size){
        return table->rows[rank].time;
    }else{
        printf("Rank fora dos limites da tabela. Retornando o último elemento");
        return table->rows[table->size - 1].time;
    }
}

void delete_min(Table *table){
    delete(table, min(table));
}

void delete_max(Table *table){
    delete(table, max(table));
}

void main()
{
    Time *time1 = create_time(12,13,14);
    Row *row1 = create_row(time1, "Primeiro");
    Time *time2 = create_time(15,16,17);
    Row *row2 = create_row(time2, "Segundo");
    Time *time3 = create_time(18,19,20);
    Row *row3 = create_row(time3, "Terceiro");
    Table *table = create_table();

    // PUT / SHIFT_RIGHT / PRINT
    // put(table,  row3);
    // put(table,  row2);
    // put(table,  row1);
    // print_table(table);

    // GET
    // put(table,  row1);
    // put(table,  row2);
    // put(table,  row3);
    // printf("%s\n", get(table, time1));
    // printf("%s\n", get(table, time2));
    // printf("%s\n", get(table, time3));

    // DELETE
    // put(table,  row1);
    // put(table,  row2);
    // put(table,  row3);
    // delete(table, time1);
    // delete(table, time2);
    // print_table(table);

    // CONTAINS
    // put(table,  row1);
    // put(table,  row2);
    // printf("%d\n", contains(table, row1->time));
    // printf("%d\n", contains(table, row3->time));

    // EMPTY
    // printf("%d\n", is_empty(table));
    // put(table,  row1);
    // printf("%d\n", is_empty(table));

    // SIZE
    // printf("%d\n", size(table));
    // put(table,  row1);
    // put(table,  row2);
    // printf("%d\n", size(table));

    // MIN
    // put(table,  row1);
    // put(table,  row2);
    // put(table,  row3);
    // print_time(min(table));
    // printf("\n");
    // Time *time4 = create_time(1,2,3);
    // Row *row4 = create_row(time4, "Teste");
    // put(table,  row4);
    // print_time(min(table));

    // MAX
    // put(table,  row1);
    // put(table,  row2);
    // put(table,  row3);
    // print_time(max(table));
    // printf("\n");
    // Time *time4 = create_time(23,23,23);
    // Row *row4 = create_row(time4, "Teste");
    // put(table,  row4);
    // print_time(max(table));

    // FLOOR
    // Time *time4 = create_time(15,16,19);
    // Row *row4 = create_row(time4, "Teste");
    // put(table,  row4);
    // put(table,  row3);
    // put(table,  row1);
    // put(table,  row2);
    // Time *time5 = create_time(15,16,20);
    // print_time(floor(table, time5));

    // CEILING
    // Time *time4 = create_time(15,16,21);
    // Row *row4 = create_row(time4, "Teste");
    // put(table,  row4);
    // put(table,  row3);
    // put(table,  row1);
    // put(table,  row2);
    // Time *time5 = create_time(15,16,20);
    // print_time(ceiling(table, time5));

    // RANK
    // put(table,  row3);
    // put(table,  row1);
    // put(table,  row2);
    // printf("%d\n", rank(table, time1));
    // printf("%d\n", rank(table, time3));

    // SELECT_BY_RANK
    // put(table,  row3);
    // put(table,  row2);
    // put(table,  row1);
    // print_time(select_by_rank(table, 0));

    // DELETE_MIN
    // put(table,  row3);
    // put(table,  row2);
    // put(table,  row1);
    // delete_min(table);
    // print_table(table);

    // DELETE_MAX
    // put(table,  row3);
    // put(table,  row2);
    // put(table,  row1);
    // delete_max(table);
    // print_table(table);
}