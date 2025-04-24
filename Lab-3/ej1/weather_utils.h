#include "weather.h"
#include "weather_table.h"

int min_temp_min(Weather weather[YEARS][MONTHS][DAYS]);
void max_temp_max(Weather weather[YEARS][MONTHS][DAYS], int output[YEARS]);
int sum_month_rainfall(Weather weather[YEARS][MONTHS][DAYS], int y, int m);
void max_month_rainfall(Weather weather[YEARS][MONTHS][DAYS], int output[YEARS]);