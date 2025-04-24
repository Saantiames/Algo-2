#include <limits.h>
#include "weather_utils.h"

int min_temp_min(Weather weather[YEARS][MONTHS][DAYS]) {

    int min = INT_MAX;
    for (int y = 0; y < YEARS; y++) {
        for (int m = 0; m < MONTHS; m++) {
            for (int d = 0; d < DAYS; d++) { //search in all day,months,years
                if (weather[y][m][d]._min_temp < min) {
                    min = weather[y][m][d]._min_temp;
                }
            }
        }
    }
    return min;
}

void max_temp_max(Weather weather[YEARS][MONTHS][DAYS], int output[YEARS]) {
    for (int y = 0; y < YEARS; y++) {       //search per year, output per year
        int max_t = weather[y][0][0]._max_temp; //select the first month as the greatest
        for (int m = 0; m < MONTHS; m++) {
            for (int d = 0; d < DAYS; d++) {
                if (weather[y][m][d]._max_temp > max_t) {
                    max_t = weather[y][m][d]._max_temp;
                }
            }
        }
        output[y] = max_t;
    }
}

int sum_month_rainfall(Weather weather[YEARS][MONTHS][DAYS], int y, int m) {
    int sum = 0;
    for (int d = 0; d < DAYS; d++) {
        sum += weather[y][m][d]._rainfall;
    }
    return sum;
}

void max_month_rainfall(Weather weather[YEARS][MONTHS][DAYS], int output[YEARS]) {
    for (int y = 0; y < YEARS; y++) {
        int best_m = 0;
        int best_rain = sum_month_rainfall(weather, y, 0);
        for (int m = 1; m < MONTHS; m++) {
            int r = sum_month_rainfall(weather, y, m);
            if (r > best_rain) {
                best_rain = r;
                best_m = m;
            }
        }
        output[y] = best_m;
    }
}

