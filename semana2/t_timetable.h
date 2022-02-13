#ifndef __T_TIMETABLE_H__
#define __T_TIMETABLE_H__
#include "t_time.h"

typedef struct t_timetable Timetable;
struct t_timetable {
    Time *time;
    char *name;
};

void print(Timetable *timetable);

void put(Timetable *timetable, Time *time, char *name);
char* get(Timetable *timetable, Time *time);
void delete(Timetable *timetable, Time *time);
int contains(Timetable *timetable, Time *time);
int is_empty(Timetable *timetable);
int size(Timetable *timetable);
Time* min(Timetable *timetable);
Time* max(Timetable *timetable);
Time* floor(Timetable *timetable, Time *time);
Time* ceiling(Timetable *timetable, Time *time);
int rank(Timetable *timetable, Time *time); // Posição na tabela (a partir da menor)
Time* select(Timetable *timetable, int k); // k-ésimo elemento (a partir da menor)
void delete_min(Timetable *timetable);
void delete_max(Timetable *timetable);
int size_range(Timetable *timetable, Time *lo, Time *hi);
void keys(Timetable *timetable, Time *lo, Time *hi); 

#endif