#ifndef __T_TIME_H__
#define __T_TIME_H__
#define TIME_LEN 9

typedef struct t_time Time;

struct t_time {
    int hour;
    int minute;
    int second;
};
void print_time(Time *time);

Time* malloc_time();
Time* create_time(int hour, int minutes, int seconds);
int time_cmp(Time* time1, Time* time2);
void time_to_string(Time* time, char* dest);
int time_to_seconds(Time *time);
#endif